#include<iostream>
using namespace std;

class DoublyEndedQueue{
    public:
    int *arr;
    int size;
    int rear;
    int front;

    DoublyEndedQueue(int size)
    {
        arr=new int[size];
        this->size=size;
        front=-1;
        rear=-1;
    }
    void pushRear(int data)
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

    void pushfront(int data)
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
            arr[front]=data;
        }
        else if(rear!=size-1 && front==0)
        {
            front==size-1;
            arr[front]=data;
        }
        else{
            front++;
            arr[front]=data;
        }
    }

    void popfront()
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

    void popRear()
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
        else if(rear==0)
        {
            rear=size-1;
        }
        else
        {
            rear--;
        }
    }

};
int main()
{
    DoublyEndedQueue q(10);
    q.pushRear(10);
    q.pushRear(20);
    q.pushRear(30);
    q.pushfront(40);
    q.pushRear(50);
    q.pushRear(60);
}