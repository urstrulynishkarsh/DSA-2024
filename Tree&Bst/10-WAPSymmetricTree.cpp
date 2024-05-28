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
bool isSameTree(Node* p, Node* q) {
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if(p!=NULL && q==NULL)
        {
            return false;
        }
        if(p==NULL && q!=NULL)
        {
            return false;
        }
        return p->data==q->data && isSameTree(p->left,q->right)  && isSameTree(p->right,q->left);
    }
int main(){
    Node *root=NULL;
    root=buildTree();
    cout<<isSameTree(root->left,root->right);

}