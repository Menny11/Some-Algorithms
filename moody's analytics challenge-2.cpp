#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* this is a challenge from hackerrank Moody's analytics contest
    details about challenge in the following link:
    https://www.hackerrank.com/contests/moodys-analytics-fall-university-codesprint/challenges/stock-purchase-day*/ 
    typedef pair<int, int> pInt;
    int n_days;
    cin>>n_days;
    
    vector<pInt> st_price(n_days);
    for (int i=0; i<n_days; ){
        cin>>st_price[i].first;
        st_price[i].second=++i;
    }
    sort(st_price.begin(), st_price.end());
   
    int n_queries;
    cin>>n_queries;
    vector<pInt> st_query(n_queries);
    for (int i=0; i<n_queries; ++i){
        cin>>st_query[i].first;
        st_query[i].second=i;
    }
    sort(st_query.begin(), st_query.end());
    
    vector<pInt>::iterator x_iter=st_price.begin(), x_iter_old=x_iter;
    vector<int> qr_answers(n_queries);
    for (int i=0, x_price=0, x_index=0, max_index=0; i<n_queries; ++i){
        x_price=st_query[i].first;
        x_index=st_query[i].second;
        x_iter=upper_bound(x_iter_old, st_price.end(), x_price, 
                       [](const int& vl, pInt& pr)
                       {return vl<pr.first;});
        if (x_iter==st_price.begin()){
            qr_answers[x_index]=-1;
            continue;
        }
        
        for(vector<pInt>::iterator it=x_iter_old; it!=x_iter; ++it){
            if (it->second>max_index)
                max_index=it->second;
        }
        --x_iter;
        qr_answers[x_index]=max_index+1;
        x_iter_old=x_iter;
    
    }
    for (auto el: qr_answers)
        cout<<el<<endl;
    return 0;
}