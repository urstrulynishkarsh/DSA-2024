#include<iostream>
#include <vector>
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

Node* mergeNodes(Node* head) {
        if(head==NULL)
        {
            return head;
        }
        Node *slow=head;
        Node *fast=head->next;
        Node *newLastNode=0;
        int sum=0;
        while(fast)
        {
            if(fast->val!=0)
            {
                sum+=fast->val;
            }
            else
            {
                slow->val=sum;
                newLastNode=slow;
                slow=slow->next;
                sum=0;
            }
            fast=fast->next;
        }
        Node *temp=slow;
        newLastNode->next=NULL;

        // delete node
        while(temp)
        {
            Node *nxt=temp->next;
            delete temp;;
            temp=nxt;
        }
        return head;
    }


int main()
{
    Node *first= new Node(0);
    Node *second=new Node(2);
    Node *third=new Node(23);
    Node *fourth=new Node(0);
    Node *fifth=new Node(5);
    Node *sixth=new Node(0);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;

    PrintNode(first);
     cout<<endl;



    

     Node *head=mergeNodes(first);
     PrintNode(head);




    
    
}