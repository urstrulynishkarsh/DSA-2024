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
 
Node *ReverseKGroups(Node *&head,int k){
    if(head==NULL)
    {
        return head;
    }
    if(head->next==NULL)
    {
        return head;
    }
    int len=getLength(head);
    if(len<k)
    {
        return head;
    }
    Node *prev=NULL;
    Node *curr=head;
    Node *temp=curr->next;
    int count=0;
    while(count<k)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        count++;
    }
    if(temp)
    {
        head->next=ReverseKGroups(temp,k);
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
    Node *sixth=new Node(60);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;

    PrintNode(first);
    cout<<endl;

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

   first = ReverseKGroups(first, k);
    PrintNode(first);
    cout<<endl;

}