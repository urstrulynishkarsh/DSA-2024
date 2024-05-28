#include<iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode *next;

        ListNode()
        {
            this->data=0;
            this->next=nullptr;
        }
        ListNode(int data)
        {
            this->data=data;
            this->next=nullptr;
        }

};

void PrintNode(ListNode *&head)
{
    ListNode *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


ListNode *findMid(ListNode *&head)
    {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast)
        {
            fast=fast->next;
            if(fast)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }

    ListNode *merge(ListNode *left,ListNode *right)
    {
        if(left==NULL)
        {
            return right;
        }
        if(right==NULL)
        {
            return left;
        }
        ListNode *ans=new ListNode(-1);
        ListNode *mptr=ans;
        while(left!=NULL && right!=NULL)
        {
            if(left->data<right->data)
            {
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else
            {
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        while(left!=NULL)
        {
             mptr->next=left;
                mptr=left;
                left=left->next;
        }
        while(right!=NULL)
        {
             mptr->next=right;
                mptr=right;
                right=right->next;
        }

        return ans->next;

    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
        {
            return head;
        }
        if(head->next==NULL)
        {
            return head;
        }
        // break the linked list into two half
        ListNode *mid=findMid(head);
        ListNode *left=head;
        ListNode *right=mid->next;
        mid->next=NULL;

        left=sortList(left);
        right=sortList(right);

        ListNode *mergeLL=merge(left,right);
        return mergeLL;
    }

int main()
{
   ListNode *first= new ListNode(20);
   ListNode *second=new ListNode(10);
    ListNode *third=new ListNode(30);
   ListNode *fourth=new ListNode(50);
    ListNode *fifth=new ListNode(40);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    PrintNode(first);
    cout<<endl;

    ListNode *head=sortList(first);
    PrintNode(head);

}