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

int getLength(Node *&head)
    {
        int len=0;
        Node *Temp=head;
        while(Temp)
        {
            len++;
            Temp=Temp->next;
        }
        return len;
    }
    Node* rotateRight(Node* head, int k) {
        if(head==NULL)
        {
            return head;
        }
        int length=getLength(head);
        int acutalRotation=k%length;
        if(acutalRotation==0)
        {
            return head;
        }
        int position=length-acutalRotation;
        int i=0;
        Node *prev=head;
        while(i<position-1)
        {
            prev=prev->next;
            i++;
        }
        Node *newHead=prev->next;
        Node *curr=newHead;
        while (curr->next != NULL) {
        curr = curr->next;
        }
        curr->next = head;
        head = newHead;
        prev->next = NULL;
        return head;
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

     int k;
     cout<<"Enter the value of k rotation: ";
     cin>>k;

     Node *head=rotateRight(first,k);

     PrintNode(head);
    
    
}