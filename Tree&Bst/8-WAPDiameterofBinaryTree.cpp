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

int HeightOfTree(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(HeightOfTree(root->left),HeightOfTree(root->right))+1;
}

int DiameterOfTree(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int d1=DiameterOfTree(root->left);
    int d2=DiameterOfTree(root->right);
    int d3=HeightOfTree(root->left)+HeightOfTree(root->right);

    return max(d3,max(d1,d2));
}

int main(){
    Node *root=NULL;
    root=buildTree();

    cout<<DiameterOfTree(root);
}