#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int> > ajdList;

    void addEdge(int u,int v, bool direction)
    {
        ajdList[u].push_back(v);
        if(direction==0)
        {
            ajdList[v].push_back(u);
        }
    }

    bool checkCycleDirectedGraphUsingDFS(int src,unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited){
        visited[src]=true;
        dfsVisited[src]=true;
        for(auto nbr:ajdList[src])
        {
            if(!visited[nbr]){
               bool nextAnswer=checkCycleDirectedGraphUsingDFS(nbr,visited,dfsVisited);
               if(nextAnswer==true)
               {
                return true;
               }
            }
            else{
                if(visited[nbr]==true && dfsVisited[nbr]==true)
                {
                    return true;
                }
            }
        }
        dfsVisited[src]=false;
        return false;
    }
};
int main(){
    Graph g;
    int n=5;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    // g.addEdge(4,2,1);


    bool ans=false;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            ans=g.checkCycleDirectedGraphUsingDFS(i,visited,dfsVisited);
            if(ans==true)
            {
                break;
            }
        }
    }
    if(ans==true)
    {
        cout<<"Cycle is present: ";
    }
    else{
        cout<<"Cycle is not present: ";
    }


}