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

void ConvertInToSumTree(Node* root) {
    if (root == NULL) {
        return;
    }
    ConvertInToSumTree(root->left);
    ConvertInToSumTree(root->right);
    int leftData = root->left ? root->left->data : 0;
    int rightData = root->right ? root->right->data : 0;
    root->data = leftData + root->data + rightData;
}

int main(){
    Node *root=NULL;
    root=buildTree();
    ConvertInToSumTree(root);
    
}