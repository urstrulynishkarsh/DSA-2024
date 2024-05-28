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

// void Sort012(Node *&head)
// {
//     Node *dummy=head;
//     int zero=0;
//     int one=0;
//     int two=0;

//     while(dummy)
//     {
//         if(dummy->data==0)
//         {
//             zero++;
//         }
//         if(dummy->data==1)
//         {
//             one++;
//         }
//         if(dummy->data==2)
//         {
//             two++;
//         }
//         dummy=dummy->next;
//     }
//     dummy=head;
//     while(zero--)
//     {
//          dummy->data=0;
//         dummy= dummy->next;
//     }
//      while(one--)
//     {
//         dummy->data=1;
//          dummy= dummy->next;
//     }
//     while(two--)
//     {
//        dummy->data=2;
//         dummy= dummy->next;
//     }

// }


Node *Sort2(Node *&head)
{
    Node *ZeroDummy=new Node(-1);
    Node *OneDummy=new Node(-1);
    Node *TwoDummy=new Node(-1);

    Node *ZeroTail=ZeroDummy;
    Node *OneTail=OneDummy;
    Node *TwoTail=TwoDummy;


    Node *curr=head;
    while(curr)
    {
        if(curr->data==0)
        {
            Node *temp=curr;
            curr=curr->next;
            temp->next=NULL;
            ZeroTail->next=temp;
            // update for tail
            ZeroTail=temp;

        }
        else if(curr->data==1)
        {
            Node *temp=curr;
            curr=curr->next;
            temp->next=NULL;
            OneTail->next=temp;
            OneTail=temp;
        }
        else if(curr->data==2)
        {
            Node *temp=curr;
            curr=curr->next;
            temp->next=NULL;
            TwoTail->next=temp;
            TwoTail=temp;
        }
      
    }


    Node *temp=OneDummy;
    OneDummy=OneDummy->next;
    temp->next=NULL;
    delete temp;


    temp=TwoDummy;
    TwoDummy=TwoDummy->next;
    temp->next=NULL;
    delete temp;

    // join list

    if(OneDummy!=NULL)
    {
        ZeroTail->next=OneDummy;
        if(TwoDummy!=NULL)
        {
            OneTail->next=TwoDummy;
        }
    }
    else{
        if(TwoDummy!=NULL)
        {
            ZeroTail->next=TwoDummy;
        }
    }

    temp=ZeroDummy;
    ZeroDummy=ZeroDummy->next;
    temp->next=NULL;
    delete temp;


    return head;

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
    
    Node *head=Sort2(first);
    PrintNode(head);
}