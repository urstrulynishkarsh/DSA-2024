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

int sum(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }    
    return sum(root->left)+root->data+sum(root->right);
}

bool CheckBTSumTree(Node *root)
{
    if(root==NULL ||(root->left==NULL &&root->right))
    {
        return true;
    }

    int leftans=sum(root->left);
    int rightans=sum(root->right);

    if((root->data==leftans+rightans)&& CheckBTSumTree(root->left) && CheckBTSumTree(root->right))
    {
        return true;
    }
    return false;
}

int main(){
    Node *root=NULL;
    root=buildTree();
    cout<<CheckBTSumTree(root);
}