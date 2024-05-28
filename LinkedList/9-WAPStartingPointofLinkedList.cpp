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
int getLength(Node *&head)
{
    int len=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
        
    }
    return len;
}

void PrintNode(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
 
Node *StartingPointOfLL(Node *&head){
   if(head==NULL)
   {
    return head;
   }
   if(head->next==NULL)
   {
    return head;
   }
   Node * slow=head;
   Node *fast=head;
   while(fast)
   {
    fast=fast->next;
    if(fast)
    {
         slow=slow->next;
          fast=fast->next;
    }
    if(slow==fast)
    {
        slow=head;
        break;
    }
   }
   while(slow!=fast)
   {
        slow=slow->next;
        fast=fast->next;
   }
   return slow;
}



int main()
{
    Node *first= new Node(10);
    Node *second=new Node(20);
    Node *third=new Node(30);
    Node *fourth=new Node(40);
    Node *fifth=new Node(50);
    Node *sixth=new Node(60);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=third;



    cout<<StartingPointOfLL(first)->data;



}