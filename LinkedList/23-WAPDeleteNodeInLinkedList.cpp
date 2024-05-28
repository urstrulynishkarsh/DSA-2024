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

void deleteNode(Node *node)
{
    cout<<node->data<<"     "<<node->next->data<<endl;
    node->data=node->next->data;
    node->next=node->next->next;
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

   

     deleteNode(first);

     PrintNode(first);
    
    
}