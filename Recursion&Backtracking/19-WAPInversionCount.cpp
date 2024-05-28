#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

    long long int Merge(long long int arr[], long long int N,long long int s,long long int e)
    {
        long long int Inversion=0;
        long long int mid=s+(e-s)/2;
        long long int len1=mid-s+1;
        long long int len2=e-mid;
        
        long long int *arr1=new long long int[len1];
        long long int *arr2=new long long int[len2];
        
        int k=s;
        for(int i=0;i<len1;i++)
        {
            arr1[i]=arr[k];
            k++;
        }
        for(int i=0;i<len2;i++)
        {
            arr2[i]=arr[k];
            k++;
        }
        
        long long int leftIndex=0;
        long long int rightIndex=0;
        long long int mainIndex=s;
        while(leftIndex<len1 && rightIndex<len2)
        {
            if(arr1[leftIndex]<=arr2[rightIndex])
            {
                arr[mainIndex++]=arr1[leftIndex++];
            }
            else
            {
                arr[mainIndex++]=arr2[rightIndex++];
                Inversion+=len1-leftIndex;
            }
        }
         while(leftIndex<len1)
         {
             arr[mainIndex++]=arr1[leftIndex++];
         }
         while(rightIndex<len2)
         {
             arr[mainIndex++]=arr2[rightIndex++];
         }
         return Inversion;
         
        
        
    }
    
    long long int MergeSort(long long int arr[], long long  int N,long long int s,long long int e)
    {
        long long int Inversion=0;
        if(s<e)
        {
            long long int mid=s+(e-s)/2;
            Inversion+=MergeSort(arr,N,s,mid);
            Inversion+=MergeSort(arr,N,mid+1,e);
            Inversion+=Merge(arr,N,s,e);
        }
        return Inversion;
    }

int main()
{
    long long int N;
    cout<<"Enter the size of array: ";
    cin>>N;
    long long int *arr=new long long int[N];
    cout<<"Enter the element in the array: ";
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    long long int s=0;
    long long int e=N-1;
    cout<<MergeSort(arr,N,s,e);
}