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
    Node *temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
        
    }
    return len;
}
int RemoveNthNode(Node *&head,int n)
{
       if(head==NULL)
    {
        return -1;
    }
    if(n<=0)
    {
        return -1;
    }
    int length=getLength(head);
    int pos=length-n;
    if(length<n)
    {
        return -1;
    }
    
    if(pos==0)
    {
        Node *temp=head;
        head=head->next;
        // temp->next=NULL;
        return temp->data;
        
    }
    int i=0;
    Node *prev=head;
    while(i<pos-1)
    {
        prev=prev->next;
        i++;
    }
    Node *curr=prev->next;
    prev->next=curr->next;
    // curr->next=NULL;
    return curr->data;
}







int main()
{
      
    Node *first= new Node(0);
    Node *second=new Node(1);
    Node *third=new Node(2);
    Node *fourth=new Node(0);
    Node *fifth=new Node(1);
    Node *sixth=new Node(1);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;

    PrintNode(first);
     cout<<endl;

     int n;
     cout<<"Enter the position which you wan to delete from the end: ";
     cin>>n;

   
    
    cout<<RemoveNthNode(first,n);
  
}