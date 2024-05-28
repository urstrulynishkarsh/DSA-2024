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

void PrintNode(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node *MiddleOfLinkedList(Node *&slow,Node *&fast){
    if(slow==NULL)
    {
        return slow;
    }
    if(slow->next==NULL)
    {
        return slow;
    }
    while(slow && fast)
    {
        fast=fast->next;
        if(slow && fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
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

    PrintNode(first);
    cout<<endl;

    

    Node *slow=first;
    Node *fast=first;
  
    MiddleOfLinkedList(slow,fast);
    PrintNode(slow);

    




}