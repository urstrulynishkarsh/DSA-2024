#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void ReverseFirstK(queue<int> &q, int k){
   stack<int>st;
   int count=0;
   int n=q.size();
   if(k==0 ||k>n)
   {
        return;
   }
   while(!q.empty())
   {
        int front=q.front();
        q.pop();
        st.push(front);
        count++;
        if(k==count)
        {
            break;
        }
   }
   while(!st.empty())
   {
        int top=st.top();
        st.pop();
        q.push(top);
   }
   count=0;
   while(!q.empty() && n-k!=0)
   {
        int front=q.front();
        q.pop();
        q.push(front);
        count++;
        if(count==n-k)
        {
            break;
        }
   }
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);  
    q.push(8);

    // while(!q.empty())
    // {
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }

    int k;
    cout<<"Enter the k value: ";
    cin>>k;

 

    ReverseFirstK(q,k);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }


}

