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

Node *ReverseLinkedList(Node *&prev, Node *&curr){
    while(curr!=NULL)
    {
        Node *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

int main()
{
    Node *first= new Node(10);
    Node *second=new Node(20);
    Node *third=new Node(30);
    Node *fourth=new Node(40);
    Node *fifth=new Node(50);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    PrintNode(first);
    cout<<endl;
    Node *Prev=NULL;
    Node *curr=first;
    ReverseLinkedList(Prev,curr);
    while(Prev!=NULL)
    {
        cout<<Prev->data<<" ";
        Prev=Prev->next;
    }




}