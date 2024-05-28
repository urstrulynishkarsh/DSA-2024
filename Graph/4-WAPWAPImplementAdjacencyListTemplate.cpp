#include<iostream>
#include<unordered_map>
#include<list>
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

};

int main(){
    Graph<char> g;
    g.addEdge('a','b',0);
    g.addEdge('b','c',0);
    g.addEdge('a','c',0);

    g.printAdjacencyList();

}