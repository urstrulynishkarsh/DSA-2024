#include<iostream>
#include<stack>
using namespace std;

class Queue{
    public:
    stack<int> s1,s2;

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int pop=-1;
        if(!s2.empty())
        {
            pop=s2.top();
        }
        else{
            while(!s1.empty())
            {
                int top=s1.top();
                s1.pop();
                s2.push(top);
            }
            pop=s2.top();
        }
        s2.pop();
        return pop;
    }

    int front()
    {
        int front=-1;
        if(!s2.empty())
        {
            front=s2.top();
        }
        else{
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
             front=s2.top();
        }
        return front;
    }

    bool isempty()
    {
        return (s1.empty() && s2.empty());
    }
    
};

int main(){
    Queue *obj=new Queue();
    obj->push(10);
    obj->push(20);
    obj->push(30);
    obj->push(40);
    obj->push(50);
    cout<<obj->pop()<<endl;
    cout<<obj->front()<<endl;
    cout<<obj->isempty();
}