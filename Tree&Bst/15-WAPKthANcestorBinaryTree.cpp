#include<iostream>
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

bool Recursion(Node *&root, int &k, int &node,int &ans)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==node)
    {
        return true;
    }
    bool leftans=Recursion(root->left,k,node,ans);
    bool rightans=Recursion(root->right,k,node,ans);
    
    if(leftans||rightans)
    {
        k--;
        if(k==0)
        {
            ans=root->data;
        }
    }
}

int kthAncestor(Node *&root, int &k, int &node)
{
    int ans=-1;
    Recursion(root,k,node,ans);
    return ans;
    // Code here
}

int main(){
    Node *root=NULL;
    root=buildTree();
    int k=2;
    int node=120;
    cout<<kthAncestor(root,k,node);
}