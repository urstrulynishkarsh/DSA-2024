#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
#include<stack>
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

    void topologicalSortUsingDFS(int src,unordered_map<int,bool> &visited,stack<int> &st){
        visited[src]=true;
        for(auto nbr:adjList[src])
        {
            if(!visited[nbr])
            {
                topologicalSortUsingDFS(nbr,visited,st);
            }
        }
         st.push(src);
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

    // g.addEdge(1,2,1);
    // g.addEdge(1,3,1);

    g.printAdjacencyList();

    stack<int> st;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.topologicalSortUsingDFS(i,visited,st);
        }
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

}