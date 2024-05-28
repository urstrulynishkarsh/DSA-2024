#include<iostream>
#include<unordered_set>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node *bottom;

        Node()
        {
            this->data=0;
            this->next=nullptr;
            this->bottom=nullptr;
        }
        Node(int data)
        {
            this->data=data;
            this->next=nullptr;
            this->bottom=nullptr;
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
        temp=temp->bottom;
    }
}

Node* sortedMerge(Node* a, Node* b)  
{  
    
     if(a==NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        Node *ans=0;
        if(a->data<b->data)
        {
            ans=a;
            a->bottom=sortedMerge(a->bottom,b);
        }
        else
        {
            ans=b;
            b->bottom=sortedMerge(a,b->bottom);
        }
         return ans;
    
    // code here
}

Node *mergeIntosingle(Node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    return sortedMerge(head,mergeIntosingle(head->next));
}



int main()
{
    Node *first= new Node(5);
    Node *second=new Node(10);
    Node *third=new Node(19);
    Node *fourth=new Node(28);
    Node *fifth=new Node(7);
    Node *sixth=new Node(8);
    Node *seven=new Node(30);
    Node *eight=new Node(20);
     Node *nine=new Node(22);
      Node *ten=new Node(50);

       Node *eleven=new Node(35);
        Node *tweleve=new Node(40);
         Node *thirteen=new Node(45);

    first->next=second;
    second->next=third;
    third->next=fourth;
   
    first->bottom=fifth;
    fifth->bottom=sixth;
    sixth->bottom=seven;

    second->bottom=eight;

    third->bottom=nine;
    nine->bottom=ten;

    fourth->bottom=eleven;
    eleven->bottom=tweleve;
    tweleve->bottom=thirteen;
    
    Node *head= mergeIntosingle(first);
    PrintNode(head);

    
}