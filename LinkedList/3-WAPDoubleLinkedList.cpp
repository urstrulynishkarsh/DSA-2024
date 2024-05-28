#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data=0;
        this->next=nullptr;
        this->prev=nullptr;
    }
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
    ~Node(){
        cout<<"Node with value "<<this->data<<" deleted"<<endl;
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

void HeadInsertion(Node *&head, Node *&tail,int data)
{
    if(head==NULL)
    {
        Node *newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node *newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void TailInsertion(Node *&head, Node *&tail,int data)
{
    if(head==NULL)
    {
        Node *newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node *newNode=new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}

void PositionInsertion(Node *&head, Node *&tail,int data, int position)
{
    if(head==NULL)
    {
        Node *newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    int length=getLength(head);
    if(position==0)
    {
        HeadInsertion(head,tail,data);
        return;
    }
    if(position>=length)
    {
        TailInsertion(head,tail,data);
        return;
    }
    int i=0;
    Node *last=head;
    while(i<position-1)
    {
        last=last->next;
        i++;
    }
    Node *curr=last->next;
    Node *newNode=new Node(data);
    newNode->next=curr;
    curr->prev=newNode;
    newNode->prev=last;
    last->next=newNode;
}

void PositionDeletion(Node *&head, Node *&tail, int position)
{
    if(head==NULL)
    {
        cout<<"LinkedList is empty so we can't delete it: "<<endl;
        return;
    }
     int length=getLength(head);
    if(position==0)
    {
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        delete temp;
        return;
    }
    if(position>=length)
    {
         cout<<"Invalid Poistion so we can't delete it: "<<endl;
        return;
    }
    if(position==length-1)
    {
        int i=0;
        Node *last=head;
        while(i<position-1)
        {
            last=last->next;
            i++;
        }
        Node *temp=tail;
        tail=last;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;    
        return;    
    }
    int i=0;
        Node *last=head;
        while(i<position-1)
        {
            last=last->next;
            i++;
        }
        Node *curr=last->next;
        last->next=curr->next;
        curr->next->prev=last;
        curr->prev=NULL;
        curr->next=NULL;
        delete curr;
}

int main(){

    Node *Head=NULL;
    Node *Tail=NULL;
    HeadInsertion(Head,Tail,10);
    HeadInsertion(Head,Tail,20);
    TailInsertion(Head,Tail,30);
    PositionInsertion(Head,Tail,40,0);
    PositionInsertion(Head,Tail,90,10);
    PositionInsertion(Head,Tail,5,2);
    PositionInsertion(Head,Tail,50,5);
    PositionInsertion(Head,Tail,80,7);
    
    cout<<"Head points to "<<Head->data<<endl;
    cout<<"Tail points to "<<Tail->data<<endl;

    PrintNode(Head);
    cout<<endl;


    PositionDeletion(Head,Tail,0);
    PositionDeletion(Head,Tail,4);
    PositionDeletion(Head,Tail,5);
    PositionDeletion(Head,Tail,6);

    cout<<"Head points to "<<Head->data<<endl;
    cout<<"Tail points to "<<Tail->data<<endl;
    cout<<endl;
    
    PrintNode(Head);


}