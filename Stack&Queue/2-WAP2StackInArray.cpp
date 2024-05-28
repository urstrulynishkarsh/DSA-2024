#include<iostream>
using namespace std;
class Stack{
    public:
    int size;
    int *arr;
    int top1;
    int top2;



    Stack(int size)
    {
        arr=new int[size];
        this->size=size;
        top1=-1;
        top2=size;
    }
    
    // function

    void push1(int data)
    {
        // space is available
        if(top2-top1==1)
        {
             cout<<"Stack is Overflow: "<<endl;
          
        }
        else{
             top1++;
            arr[top1]=data;
        }

    }

    void push2(int data)
    {
        if(top2-top1==1)
        {   
            cout<<"Stack is Overflow: "<<endl;
        }
        else{
            top2--;
            arr[top2]=data;
        }
    }

    void pop1()
    {
        if(top1==-1)
        {
            cout<<"Stack is Underflow: "<<endl;
        }
        else{
            top1--;
        }
    }

    void pop2()
    {
        if(top2==size)
        {
            cout<<"Stack is Underflow: "<<endl;
        }
        else{
            top2++;
        }

    }

    int getTop1()
    {
        if(top1==-1)
        {
            cout<<"Stack is Empty: ";
            return 0;
        }
       else{
            return arr[top1];
       }
    }
    int getsizetop1()
    {
        return top1+1;
    }

    int getTop2()
    {
        if(top1==size)
        {
            cout<<"Stack is Empty: ";
            return 0;
        }
       else{
            return arr[top2];
       }
    }
    int getsizetop2()
    {
         return size - top2;
    }


    bool isEmptyTop1()
    {
        if (top1 == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmptyTop2()
    {
        if (top2 == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



};


int main()
{

     Stack s(10);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);

    s.push2(60);
    s.push2(70);
    s.push2(80);
    s.push2(90);
    // s.push2(100);

    cout << "Top value first stack is:" << s.getTop1() << endl;
    cout << "Top value second stack is:" << s.getTop2() << endl;
    cout << "size of stack1 is:" << s.getsizetop1() << endl;
    cout << "size of stack2 is:" << s.getsizetop2() << endl;

}