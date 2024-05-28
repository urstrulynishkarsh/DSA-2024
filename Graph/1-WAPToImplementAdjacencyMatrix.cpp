#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    vector<vector<int> > adj(n,vector<int>(n,0));

    int e;
    cout<<"Enter the number of egdes: ";
    cin>>e;

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
    }

    for(auto ele:adj)
    {
        for(auto val:ele){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}