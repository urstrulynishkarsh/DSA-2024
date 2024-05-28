#include<iostream>
using namespace std;

class NQueue{
    int *arr,*front,*rear,*next;
    int n,k;
    int freeSpot;
    public:
    NQueue(int _n,int _k):n(_n),k(_k),freeSpot(0){
        arr=new int[n];
        next=new int[n];
        rear=new int[k];
        rear=new int[k];
        for(int i=0;i<k;i++)
        {
            rear[i]=front[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            next[i]=i+1;
        }
        next[n-1]=-1;
    }


    bool push(int x,int qi)
    {
        // overflow
        if(freeSpot==-1)
        {
            return false;
        }
        // find first free index
        int index=freeSpot;

        // update free spot
        freeSpot=next[index]; 

        // if first element in the queue i
        if(front[qi]==-1)
        {
            front[qi]=index;
        }
        else{
            next[rear[qi]]=index;
        }

        // update next;
        next[index]=-1;

        // update rear 
        rear[qi]=index;

        arr[index]=x;


        return true;

    }

    int pop(int qi)
    {
        // underflow
        if(front[qi]==-1)
        {
            return -1;
        }
        // find index to pop
        int index=front[qi];
        // front ko update
        front[qi]=next[index];
        // manage free spot
        next[index]=freeSpot;
        freeSpot=index;
          if (front[qi] == -1) {
        rear[qi] = -1;
    }
        return arr[index];
    }
    // ~NQueue(){
    //     delete[] arr;
    //     delete[] next;
    //     delete[] front;
    //     delete[] rear;
    // }
};


int main(){
     NQueue kq(8, 3);
    cout << kq.push(1, 0) << endl;
    cout << kq.push(2, 0) << endl;
    cout << kq.push(5, 1) << endl;
    cout << kq.push(3, 0) << endl;
    cout << kq.pop(1);


}