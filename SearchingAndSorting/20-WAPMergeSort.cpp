#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int> &v,int n,int s, int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    vector<int> v1(len1);
    vector<int> v2(len2);

    int k=s;
    for(int i=0;i<v1.size();i++)
    {
        v1[i]=v[k];
        k++;
    }
    k=mid+1;
    for(int i=0;i<v2.size();i++)
    {
        v2[i]=v[k];
        k++;
    }

    int leftIndex=0;
    int rightIndex=0;
    int mainIndex=s;

    while(leftIndex<len1 && rightIndex<len2)
    {
        if(v1[leftIndex]<v2[rightIndex])
        {
            v[mainIndex++]=v1[leftIndex++];
        }
        else{
            v[mainIndex++]=v2[rightIndex++];
        }
    }
    while(leftIndex<len1)
    {
        v[mainIndex++]=v1[leftIndex++];
    }
     while(rightIndex<len2)
     {
         v[mainIndex++]=v2[rightIndex++];
     }
}

void mergeSort(vector<int> &v,int n,int s, int e)
{
    int mid=s+(e-s)/2;
    if(s>=e)
    {
        return ;
    }
    mergeSort(v,n,s,mid);
    mergeSort(v,n,mid+1,e);
    Merge(v,n,s,e);
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the element in the array: ";
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int s=0;
    int e=n-1;
    mergeSort(v,n,s,e);
    for(auto val: v)
    {
        cout<<val<<" ";
    }
}