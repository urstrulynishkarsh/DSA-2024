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

Node * Removeduplicates(Node *&head)
{
    Node *curr=head;
    while(curr)
    {
        if(curr->next!=NULL && curr->data==curr->next->data){
            Node *temp=curr->next;
            curr->next=curr->next->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
    return head;

}


int main()
{
    Node *first= new Node(10);
    Node *second=new Node(20);
    Node *third=new Node(20);
    Node *fourth=new Node(20);
    Node *fifth=new Node(20);
    Node *sixth=new Node(10);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;

     PrintNode(first);
     cout<<endl;
    
    Node *RemoveLinkedList=Removeduplicates(first);
    PrintNode(RemoveLinkedList);
}