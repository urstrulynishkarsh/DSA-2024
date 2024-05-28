#include<iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int> &s,int &target)
{
    if(s.size()==0)
    {
        s.push(target);
        return;
    }
    int top=s.top();
    s.pop();
    insertBottom(s,target);
    s.push(top);
}

void ReverseStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int target=s.top();
    s.pop();
    ReverseStack(s);
    insertBottom(s,target);
}


int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

   ReverseStack(s);

    cout<<"Priting stack after insertion in bottom: "<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}