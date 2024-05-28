#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
using namespace std;

class Graph{
     public:
    unordered_map<int,list<int> > adjList;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if(direction==0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for(auto node:adjList)
        {
            cout<<node.first<<"->";
            for(auto val:node.second)
            {
                cout<<val<<',';
            }
            cout<<endl;
        }
    }

    void TopologicalSortingUsingBFS(int n,vector<int> &ans)
    {

        // make queue and indegree map 
        queue<int> q;
        unordered_map<int,int> indegree;

        // in degree calculation
        for(auto node:adjList)
        {
            int src=node.first;
            for(auto nbr:node.second)
            {
                indegree[nbr]++;
            }
        }
    }

};
int main(){
    Graph g;
    int n=8;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(6,7,1);
    g.addEdge(5,6,1);
}