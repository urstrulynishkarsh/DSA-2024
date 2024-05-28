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

    bool CycleDetectionUsingDFS(int src,unordered_map<int,bool> &visited,int parent){
        visited[src]=true;
        for(auto nbr:ajdList[src])
        {
            if(!visited[nbr])
            {
                bool NextAnswer=CycleDetectionUsingDFS(nbr,visited,src);
                if(NextAnswer==true)
                {
                    return true;
                }
            }
            else{
                if(nbr!=parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

};
int main(){
    Graph g;
    int n=5;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(3,4,0);


    bool ans=false;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            ans=g.CycleDetectionUsingDFS(i,visited,-1);
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