#include<iostream>
#include <vector>
#include<unordered_set>
using namespace std;
class Node{
    public:
        int val;
        Node *next;

        Node()
        {
            this->val=0;
            this->next=nullptr;
        }
        Node(int val)
        {
            this->val=val;
            this->next=nullptr;
        }
        ~Node(){
        cout<<"Node with value "<<this->val<<" deleted"<<endl;
    }

};

void PrintNode(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

vector<int> nodesBetweenCriticalPoints(Node* &head) {
      std::vector<int> ans = {-1, -1};
        Node *prev=head;
        Node *curr=head->next;
        Node *nxt=head->next->next;
        if(prev==NULL ||curr==NULL || nxt==NULL)
        {
            return ans;
        }
        int firstCP=-1;
        int lastCP=-1;
        int minDistance=INT_MAX;
        int i=1;
        while(nxt)
        {
            bool isCP=((curr->val>prev->val && curr->val>nxt->val)||(curr->val<prev->val && curr->val<nxt->val))?true:false;

            if(isCP && firstCP==-1)
            {
                firstCP=i;
                lastCP=i;
            }
            else if(isCP)
            {
                minDistance=min(minDistance,i-lastCP);
                lastCP=i;
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            nxt=nxt->next;
        }
        
    if(lastCP==firstCP)
        {
            return ans;
        }
        else
        {
            ans[0]=minDistance;
            ans[1]=lastCP-firstCP;
        }
    return ans;
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



    

     nodesBetweenCriticalPoints(first);


    
    
}