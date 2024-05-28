#include<iostream>
using namespace std;

class Stack{
    public:
        int top;
        int *arr;
        int size;

        Stack(int size)
        {
            arr=new int[size];
            this->size=size;
            top=-1;
        }

        // function
        void push(int data)
        {

            // space available
            if(size-top>1)
            {   
                top++;
                arr[top]=data;
            }
            else{
                cout<<"Stack is Overflow: "<<endl;
            }
        }

        void pop()
        {
            if(top==-1)
            {
                cout<<"stack is underFlow: "<<endl;
            }
            else{
                top--;
            }
        }

        int getTop()
        {
            if(top==-1)
            {
                cout<<"Stack is Empty: "<<endl;
                return 0;
            }
            else{
                return arr[top];
            }
        }

        int getSize()
        {
           
            return top+1;
            
        }

        bool isEmpty()
        {
            if(top==-1)
            {
               return 1;
            }
            else{
                return 0;
            }
        }

};

int main()
{
    Stack sta(2);
    // st.getTop();
    sta.push(1);
    sta.push(2);
    sta.push(3);
      cout<<endl<<"size of stack: "<<sta.getSize()<<endl;
      cout<<"stack is empty or not: "<<sta.isEmpty()<<endl;

    while(!sta.isEmpty())
    {
        cout<<sta.getTop()<<" ";
        sta.pop();
    }

    cout<<endl<<"size of stack: "<<sta.getSize()<<endl;
          cout<<"stack is empty or not: "<<sta.isEmpty()<<endl;





}