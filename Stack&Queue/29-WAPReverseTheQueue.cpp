#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void  ReverseQueue(stack<int> &st,queue<int> &q)
{
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        st.push(top);
    }
    while(!st.empty())
    {
        int top=st.top();
        st.pop();
        q.push(top);
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


    stack<int>st;
    ReverseQueue(st,q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }


}