#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int rear;
    int front;
    int size;

    CircularQueue(int size)
    {
        arr=new int[size];
        this->size=size;
        front=-1;
        rear=-1;
    }

    void push(int data)
    {
        if((front==0 && rear==size-1)||(rear==(front-1)%(size-1)))
        {
            cout<<"Queue is full: "<<endl;
            return;
        }
        // one case extra handle
        else if(front==-1)
        {
            front=rear=0;
            arr[rear]=data;
        }
        else if(rear==size-1 && front!=0)
        {
            rear=0;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }
    }

    void pop()
    {
        if(front==-1)
        {
            cout<<"Queue is Empty: ";
            return;
        }
        else if(front==rear)
        {
            arr[front]=-1;
            front=rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
    }

};
int main(){
    CircularQueue q(10);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
}