#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int> > > adjlist;

    void addEdge(int u,int v,int weight,bool direction){
        // if direction=0 undirected graph
        // if direction=1 directed graph 
        // adjlist[u].push_back({v,weight});
        adjlist[u].push_back(make_pair(v,weight));
        if(direction==0)
        {
             adjlist[v].push_back(make_pair(u,weight));
        }
    }

    void printAdjacenyList()
    {
        for(auto node:adjlist){
            cout<<node.first<<"->";
            for(auto neigbour:node.second)
            {
                cout<<"("<<neigbour.first<<","<<neigbour.second<<"),";
            }
            cout<<endl;
        }
    }


};


int main(){
   Graph g;
   g.addEdge(0,1,2,1);

   g.addEdge(1,2,5,1);
    g.addEdge(0,2,4,1);


   g.printAdjacenyList();
}