#include<iostream>
#include <vector>
#include<stack>
#include<unordered_set>
using namespace std;
class Node{
    public:
        int val;
        Node *next;

        Node()
        {
            this->val=0;
            this->next=nullptr;
        }
        Node(int val)
        {
            this->val=val;
            this->next=nullptr;
        }
        ~Node(){
        cout<<"Node with value "<<this->val<<" deleted"<<endl;
    }

};

void PrintNode(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
vector<int> nextLargerNodes(Node* head) {
        vector<int> ll;
        stack<int> st;
        while(head)
        {
            ll.push_back(head->val);
            head=head->next;
        }
        vector<int> ans(ll.size());
        for(int i=0;i<ll.size();i++)
        {
            while(!st.empty() && ll[i]>ll[st.top()])
            {
                int top=st.top();
                st.pop();
                ans[top]=ll[i];
            }
             st.push(i);
        
        }
        return ans;
    }


int main()
{
    Node *first= new Node(1);
    Node *second=new Node(2);
    Node *third=new Node(23);
    Node *fourth=new Node(4);
    Node *fifth=new Node(5);
    Node *sixth=new Node(6);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;

    PrintNode(first);
     cout<<endl;

    vector<int> ans=nextLargerNodes(first);

    for(auto val:ans)
    {
        cout<<val<<" ";
    }


    
    
}