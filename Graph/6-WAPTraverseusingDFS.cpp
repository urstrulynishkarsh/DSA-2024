#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>

class Graph{
    public:

    unordered_map<T,list<T> > adjList;

    void addEdge(T u,T v, bool direction)
    {
        adjList[u].push_back(v);
        if(direction==0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList(){
        for(auto node:adjList)
        {
            cout<<node.first<<"->";
           for(auto neigbour:node.second)
            {
                cout<<neigbour<<",";
            }
            cout<<endl;
        }
    }

    void dfs(T src, unordered_map<T,bool> &visited)
    {
        cout<<src<<",";
        visited[src]=true;
        for(auto neighbour:adjList[src])
        {
            if(!visited[neighbour])
            {
                dfs(neighbour,visited);
            }
        }
    }
};

int main(){
    Graph<int> g;
    int n=5;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);

    g.printAdjacencyList();
    cout<<endl;

    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
           g.dfs(i,visited);
        }
    }

}