#include<iostream>
#include<stack>
using namespace std;

void findMiddle(stack<int> &s, int totalsize)
{
    // base case
    if(s.size()==(totalsize/2)+1)
    {
        cout<<s.top();
        return;
    }
    if(s.size()==0)
    {
        cout<<"No element is found because Stack is emepty: ";
        return;
    }
    int top=s.top();
    s.pop();
    findMiddle(s,totalsize);
    s.push(top);

}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    findMiddle(s,s.size());



}
