#include<iostream>
#include<queue>
using namespace std;

class MyStack{
    public:
        queue<int> q;

        void push(int x)
        {
            q.push(x);
            for(int i=0;i<q.size()-1;i++)
            {
                int front=q.front();
                q.pop();
                q.push(front);
            }
        }

        int pop()
        {
            int front=q.front();
            q.pop();
            return front;
        }
        int top()
        {
            return q.front();
        }
        bool isempty()
        {
            return q.empty();
        }

};

int main()
{
    MyStack* obj = new MyStack();
    obj->push(10);
    obj->push(20);
    obj->push(30);
    obj->push(40);
    obj->push(50);

    cout<<obj->top()<<endl;

    obj->pop();
     cout<<obj->top()<<endl;


}