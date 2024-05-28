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

Node *LCA(Node *root, Node *p,Node *q)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==p->data)
    {
        return p;
    }
     if(root->data==q->data)
    {
        return q;
    }

    Node *leftAns=LCA(root->left,p,q);
    Node *rightAns=LCA(root->right,p,q);

    if(leftAns==NULL && rightAns==NULL)
    {
        return NULL;
    }
    else if(leftAns!=NULL && rightAns==NULL)
    {
        return leftAns;
    }
    else if(leftAns==NULL && rightAns!=NULL)
    {
        return rightAns;
    }
    else{
        return root;
    }

}

int main(){
    Node *root=NULL;
    root=buildTree();
    Node *lca=LCA(root,root->left->right,root->right->left->right);
    cout<<lca->data;
    
}