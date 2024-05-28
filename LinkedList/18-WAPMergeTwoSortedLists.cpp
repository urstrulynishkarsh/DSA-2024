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



Node* sortedMerge(Node* list1, Node* list2)  
{  
    
     if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        Node *ans=new Node(-1);
        Node *mptr=ans;

        while(list1 && list2)
        {
            if(list1->data<list2->data)
            {
                mptr->next=list1;
                mptr=list1;
                list1=list1->next;
            }
            else
            {
                 mptr->next=list2;
                mptr=list2;
                list2=list2->next;
            }
        }
         while(list1)
         {
             mptr->next=list1;
                mptr=list1;
                list1=list1->next;
         }
         while(list2)
         {
             mptr->next=list2;
                mptr=list2;
                list2=list2->next;
         }
         Node *temp=ans;
         ans=ans->next;
         temp->next=NULL;
         delete temp;

         return ans;

}







int main()
{
      
    Node *first= new Node(1);
    Node *second=new Node(2);
    Node *third=new Node(3);
    Node *fourth=new Node(4);
    Node *fifth=new Node(1);
    Node *sixth=new Node(2);
    Node *seven=new Node(3);
    Node *eight=new Node(4);

    first->next=second;
    second->next=third;
    third->next=fourth;
   
   fifth->next=sixth;
   sixth->next=seven;
   seven->next=eight;


    PrintNode(first);
     cout<<endl;

    PrintNode(fifth);
     cout<<endl;

    Node *head=sortedMerge(first,fifth);
     PrintNode(head);

}