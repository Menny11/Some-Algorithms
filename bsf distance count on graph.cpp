#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int main() {
    /* bfs on the undirected graph, used here to calculate distance
    on it from the startNode. startNode program receive from cin.
    Length of each edge is 6, and is stored in the edgeLen variable.
    Nodes have numbers from 1 to nodesNum and there are edgesNum amount 
    of edges*/
    const int edgeLen=6;
    int queriesNum;
    cin>>queriesNum;
    for (int nodesNum, edgesNum, query=0; query<queriesNum; ++query)
    {
        cin>>nodesNum>>edgesNum;
        //vector to store nodes of a graph
        vector<vector<int>> nodes(nodesNum+1, vector<int> ());
        for (int aNode, bNode, i=0; i<edgesNum; ++i)
        {
            // input of nodes info
            cin>>aNode>>bNode;
            nodes[aNode].push_back(bNode);
            nodes[bNode].push_back(aNode);
        }
        int startNode;
        //start node for distance counting
        cin>>startNode;
        /*vector to store distances. If node is not connected to
        starting node then its distance from it is -1*/
        vector<int> distToNode(nodesNum+1, -1);
        distToNode[startNode]=0;
        queue<int> nodesToCheck;
        nodesToCheck.push(startNode);
        int currentNode=0;
        //now perform bsf on the graph using queue
        while (!nodesToCheck.empty())
        {
            currentNode=nodesToCheck.front();
            nodesToCheck.pop();
            for (vector<int>::iterator nodeIt=nodes[currentNode].begin();
                nodeIt!=nodes[currentNode].end(); ++nodeIt)
            {
                if (distToNode[*nodeIt]==-1 ||
                    distToNode[*nodeIt]>distToNode[currentNode]+edgeLen){
                    distToNode[*nodeIt]=distToNode[currentNode]+edgeLen;
                    nodesToCheck.push(*nodeIt);
                }
            }
        }
        for (int i=1; i<=nodesNum; ++i)
            if (distToNode[i]!=0) cout<<distToNode[i]<<' ';
        cout<<endl;
   }
    return 0;
}
