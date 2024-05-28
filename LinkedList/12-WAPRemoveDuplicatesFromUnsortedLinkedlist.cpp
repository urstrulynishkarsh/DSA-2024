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

void Removeduplicates(Node *&head)
{
    unordered_set<int> seen;
    Node *prev=NULL;
    Node *curr=head;
    while(curr)
    {
        if(seen.find(curr->data)!=seen.end())
        {
            prev->next=curr->next;
            delete curr;
            curr=prev->next;   // dont update previous;
        }
        else{
            seen.insert(curr->data);
            prev=curr;
            curr=curr->next;

        }
    }

}


int main()
{
    Node *first= new Node(4);
    Node *second=new Node(1);
    Node *third=new Node(4);
    Node *fourth=new Node(2);
    Node *fifth=new Node(3);
    Node *sixth=new Node(2);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;

     PrintNode(first);
     cout<<endl;
    
    Removeduplicates(first);
    PrintNode(first);
}