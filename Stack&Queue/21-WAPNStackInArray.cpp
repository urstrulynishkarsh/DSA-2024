#include<iostream>
using namespace std;

class Nstack{
  
    int *arr,*top,*nxt;
    int n,size;
    int freeSpot;
    public:
    Nstack(int _n,int _s):n(_n),size(_s){
        freeSpot=0;
        arr=new int[size];
        top=new int[n];
        nxt=new int[size];

        for(int i=0;i<n;i++)
        {
            top[i]=-1;
        }

        for(int i=0;i<size;i++)
        {
            nxt[i]=i+1;
        }
        nxt[size-1]=-1;
    }

    bool push(int x, int m)
    {
        if(freeSpot==-1)
        {
            return false; // stack is overlfow
        }

        //1 find index
        int index=freeSpot;

        // 2 update freespot
        freeSpot=nxt[index];

        // 3 insert
        arr[index]=x;

        // 4 update next
        nxt[index]=top[m-1];

        // 5 update top
        top[m-1]=index;

        return true;
    }

    int pop(int m)
    {
        if(top[m-1]==-1)
        {
            return -1; // stack is underflow
        }

        // reverse all push operation 
        int index=top[m-1];
        top[m-1]=nxt[index];
        int poppedELement=arr[index];
        nxt[index]=freeSpot;
        freeSpot=index;
        return poppedELement;
    }

    ~Nstack()
    {
        delete[] arr;
        delete[] top;
        delete[] nxt;
    }
};

int main()
{
    Nstack s(3,6);

    cout<<s.push(10,1)<<endl;
    cout<<s.push(20,1)<<endl;
    cout<<s.push(30,1)<<endl;
    cout<<s.push(40,1)<<endl;

    cout<<s.push(14,2)<<endl;

    cout<<s.push(15,3)<<endl;
    // cout<<s.push(30,1)<<endl;

    cout<<s.pop(2)<<endl;
    cout<<s.pop(1)<<endl;

}