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

    void bfs(T src, unordered_map<T,bool> &visited)
    {
        queue<T> q;
       
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T frontNode=q.front();
            q.pop();
            cout<<frontNode<<",";
            for(auto neighbour:adjList[frontNode])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }



};

int main(){
    Graph<int> g;
    int n=8;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);

    g.printAdjacencyList();
    cout<<endl;

    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
           g.bfs(i,visited);
        }
    }

}