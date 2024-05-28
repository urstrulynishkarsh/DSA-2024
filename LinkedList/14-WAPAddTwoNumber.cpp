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

 Node* addTwoNumbers(Node* &FirstLL, Node* &SecondLL) {
       
        Node *AnsHead=NULL;
        Node *AnsTail=NULL;
        int carry=0;
        while(FirstLL && SecondLL)
        {
            int sum=carry+SecondLL->data+FirstLL->data;
            int digit=sum%10;
            carry=sum/10;

            Node *newNode=new Node(digit);

            if(AnsHead==NULL)
            {
                AnsHead=newNode;
                AnsTail=newNode;
            }
            else
            {
                AnsTail->next=newNode;
                AnsTail=newNode;
            }
            FirstLL=FirstLL->next;
            SecondLL=SecondLL->next;
        }
        while(FirstLL)
        {
             int sum=carry+FirstLL->data;
            int digit=sum%10;
            carry=sum/10;
                     Node *newNode=new Node(digit);
                 AnsTail->next=newNode;
                AnsTail=newNode;
                 FirstLL=FirstLL->next;
        }
        while(SecondLL)
        {
            int sum=carry+SecondLL->data;
            int digit=sum%10;
            carry=sum/10;
                Node *newNode=new Node(digit);
                 AnsTail->next=newNode;
                AnsTail=newNode;
                SecondLL=SecondLL->next;
        }
        while(carry)
        {
             int sum=carry;
            int digit=sum%10;
            carry=sum/10;
               Node *newNode=new Node(digit);
                 AnsTail->next=newNode;
                AnsTail=newNode;

        }
        return AnsHead;

}
int main()
{
    Node *first= new Node(2);
    Node *second=new Node(3);
    Node *third=new Node(4);
    Node *fourth=new Node(5);
    Node *fifth=new Node(6);
    Node *sixth=new Node(7);

    first->next=second;
    second->next=third;
  
    fourth->next=fifth;
    fifth->next=sixth;




    
    PrintNode(first);
     cout<<endl;
     PrintNode(fourth);
     cout<<endl;

     Node *head=addTwoNumbers(first,fourth);

     PrintNode(head);


    
}