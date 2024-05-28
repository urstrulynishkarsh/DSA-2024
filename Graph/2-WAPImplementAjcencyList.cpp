#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int> > adjlist;

    void addEdge(int u,int v,bool direction){
        // if direction=0 undirected graph
        // if direction=1 directed graph 
        adjlist[u].push_back(v);
        if(direction==0)
        {
            adjlist[v].push_back(u);
        }
    }

    void printAdjacenyList()
    {
        for(auto node:adjlist){
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
   Graph g;
   g.addEdge(0,1,0);
   g.addEdge(0,3,0);
   g.addEdge(1,2,0);
   g.addEdge(2,3,0);
   g.addEdge(1,3,0);
   g.printAdjacenyList();
}