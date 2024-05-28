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

void solve(Node* root, int &targetSum,vector<vector<int> > &result, vector<int> &ans, int sum)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        sum+=root->data;
        if(sum==targetSum)
        {
            result.push_back(ans);
        }
        ans.pop_back();
        sum-=root->data;
    }
    ans.push_back(root->data);
    sum+=root->data;
    solve(root->left,targetSum,result,ans,sum);
     solve(root->right,targetSum,result,ans,sum);
     ans.pop_back();
     sum-=root->data;
}
vector<vector<int> > pathSum(Node* root, int &targetSum) {
        vector<vector<int> > result;
        int sum=0;
        vector<int> ans;
        solve(root,targetSum,result,ans,sum);
        return result;
}

int main(){
    Node *root=NULL;
    root=buildTree();
    int targetSum=22;
    vector<vector<int> > v1=pathSum(root, targetSum);


   for(const auto& path : v1) {
        for(int value : path) {
            cout << value << " ";
        }
        cout << endl;
    }

}