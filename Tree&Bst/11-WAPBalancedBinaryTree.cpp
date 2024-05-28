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

 bool isBalanced(Node* root) {
        if(root==NULL)
        {
            return true;
        }
        int leftheight=HeightOfTree(root->left);
        int rightheight=HeightOfTree(root->right);

        int diff=abs(leftheight-rightheight);

        bool ans1=diff<=1;

        bool leftans=isBalanced(root->left);
        bool rightans=isBalanced(root->right);

        if(ans1 && leftans && rightans)
        {
            return true;
        }
        return false;
}

int main(){
    Node *root=NULL;
    root=buildTree();
    cout<<isBalanced(root);
}