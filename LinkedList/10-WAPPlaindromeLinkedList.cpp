#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

        Node()
        {
            this->data=0;
            this->next=nullptr;
        }
        Node(int data)
        {
            this->data=data;
            this->next=nullptr;
        }

};

Node *reverse(Node *&head)
{
    Node *prev=NULL;
    Node *curr=head;
    Node *temp=curr->next;
    while(curr)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;

}


bool CheckPalindrome(Node *&head)
{
    if(head==NULL)
    {
        return true;
    }
    if(head->next==NULL)
    {
        return true;
    }

    // find middle
    Node *slow=head;
    Node *fast=head->next;
    while(fast)
    {
        fast=fast->next;
        if(fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    Node *ReverseLLKaHead=reverse(slow->next);
    slow->next=ReverseLLKaHead;
    
    while(ReverseLLKaHead)
    {
        if(head->data!=ReverseLLKaHead->data)
        {
            return false;
        }
        else{
            head=head->next;
            ReverseLLKaHead=ReverseLLKaHead->next;
        }

    }
    return true;
}


int main()
{
    Node *first= new Node(10);
    Node *second=new Node(20);
    Node *third=new Node(30);
    Node *fourth=new Node(30);
    Node *fifth=new Node(20);
    Node *sixth=new Node(10);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    // sixth->next=third;



    cout<<CheckPalindrome(first);
}