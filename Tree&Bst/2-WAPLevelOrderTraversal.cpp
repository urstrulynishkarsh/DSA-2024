#include<iostream>
#include<vector>
#include<queue>
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

vector<vector<int> > levelOrder(Node* root){
    vector<vector<int> > result;
    if(root==NULL)
    {
        return result;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int> ans;
        for(int i=0;i<size;i++)
        {
            Node *temp=q.front();
            q.pop();
            ans.push_back(temp->data);
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        result.push_back(ans);
    }
    return result;
}

int main(){
    Node *root=NULL;
    root=buildTree();

    vector<vector<int> >result=levelOrder(root);
    for(auto val:result)
    {
        for(auto level:val)
        {
            cout<<level<<" ";
        }
        cout<<endl;
    }
}