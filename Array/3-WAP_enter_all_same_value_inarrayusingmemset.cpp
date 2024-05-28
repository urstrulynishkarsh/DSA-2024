#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    memset(arr,-1,sizeof(arr));
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}