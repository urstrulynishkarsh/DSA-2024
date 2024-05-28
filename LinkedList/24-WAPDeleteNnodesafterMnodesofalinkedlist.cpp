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

void linkdelete(struct Node  *head, int M, int N)
    {
        if(head==NULL)
        {
            return;
        }
        Node*it=head;
        for(int i=0;i<M-1;i++)
        {
            if(it==NULL)
            {
                return;
            }
            it=it->next;
        }
            if(it==NULL)
            {
                return;
            }
        Node *MthNode=it;
        it=MthNode->next;
        for(int i=0;i<N;i++)
        {
            if(it==NULL)
            {
                break;
            }
            Node *temp=it->next;
            delete it;
            it=temp;
        }
        MthNode->next=it;
         linkdelete(it,M,N);
        
        
        //Add code here   
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

     int M;
     cout<<"ENter the value which you want to save: ";
     cin>>M;

     int N;
     cout<<"ENter the value which you want to delete: ";
     cin>>N;

  linkdelete(first,M,N);

     PrintNode(first);
    
    
}