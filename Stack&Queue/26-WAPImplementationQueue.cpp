#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int rear;
    int front;
    int size;

    Queue(int size)
    {
        arr=new int[size];
        this->size=size;
        front=0;
        rear=0;
    }

    void push(int data)
    {
        if(rear==size)
        {
            cout<<"Queue is full: "<<endl;
            return;
        }
        else{
            arr[rear++]=data;
        }
    }
    void pop()
    {
        if(front==rear)
        {
            cout<<"Queue is empty: "<<endl;
            return;
        }
        else{
            arr[front]=-1;
            front++;
            if(front==rear)
            {
                front=rear=0;
            }
        }
    }
    bool isEmpty()
    {
        if(front==rear)
        {
            return true;
        }
        else{
            return false;
        }
    }
    int getSize()
    {
        return rear-front;
    }

    int getFront()
    {
        if(front==rear)
        {
            cout<<"queue is empty: ";
            return -1;
        }
        else{
            return arr[front];
        }
    }

};

int main(){

    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
     q.push(60);

    cout<<"size of queue: "<<q.getSize()<<endl;
    cout<<"is empty: "<<q.isEmpty()<<endl;
    cout<<"getfront: "<<q.getFront()<<endl;
    cout<<"is empty: "<<q.isEmpty()<<endl;

    while(!q.isEmpty())
    {
        cout<<q.getFront()<<" ";
        q.pop();
    }
    
}