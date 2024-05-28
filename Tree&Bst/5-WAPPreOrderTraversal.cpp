

















#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        this->data=0;
        this->left=NULL;
        this->right=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node *buildTree()
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    Node *root=new Node(data);
    cout<<"Enter the data for left part of "<<data<<" node"<<endl;
    root->left=buildTree();
     cout<<"Enter the data for right part of "<<data<<" node"<<endl;
    root->right=buildTree();
    return root;
}

void solve(Node *root,vector<int> &ans){
     if(root==NULL)
     {
         return;
     }
       ans.push_back(root->data);
     solve(root->left,ans);
   
     solve(root->right,ans);
 }

int main(){
    Node *root=NULL;
    root=buildTree();

    vector<int> ans;
    solve(root,ans);
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
}

