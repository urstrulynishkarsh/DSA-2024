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

    bool checkCycleUsingBFS(int src,unordered_map<int,bool> &visited)
    {
        unordered_map<int,int> parent;
        queue<int> q;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;

        while(!q.empty())
        {
            int frontnode=q.front();
            q.pop();

            for(auto nbr:ajdList[frontnode])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontnode;
                }
                else{
                    if(nbr!=parent[frontnode])
                    {
                        return true;
                    }
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
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);

    bool ans=false;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            ans=g.checkCycleUsingBFS(i,visited);
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