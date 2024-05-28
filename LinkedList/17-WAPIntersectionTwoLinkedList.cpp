#include<iostream>
#include<unordered_set>
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
        ~Node(){
        cout<<"Node with value "<<this->data<<" deleted"<<endl;
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

Node *getIntersectionNode(Node *&headA,Node *&headB)
{
    Node *A=headA;
    Node *B=headB;
    while(A->next!=NULL && B->next!=NULL)
    {
        if(A==B)
        {
            return A;
        }
        A=A->next;
        B=B->next;
    }
    if(A->next==NULL)
    {
        int blen=0;
        while(B->next!=NULL)
        {
            blen++;
            B=B->next;
        }
        while(blen--)
        {
            headB=headB->next;
        }
    }
    else{
        int alen=0;
        while(A->next!=NULL)
        {
            alen++;
            A=A->next;
        }
        while(alen--)
        {
            headA=headA->next;
        }
    }
    while(headA!=headB)
    {
         headA=headA->next;
         headB=headB->next;
    }
    return headA;
}








int main()
{
      
    Node *first= new Node(4);
    Node *second=new Node(1);
    Node *third=new Node(8);
    Node *fourth=new Node(4);
    Node *fifth=new Node(5);
    Node *sixth=new Node(5);
    Node *seven=new Node(6);
    Node *eight=new Node(1);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
   
   sixth->next=seven;
   seven->next=eight;
   eight->next=third;


    PrintNode(first);
     cout<<endl;

    PrintNode(sixth);
     cout<<endl;

    Node *head=getIntersectionNode(first,sixth);
     PrintNode(head);


  
}