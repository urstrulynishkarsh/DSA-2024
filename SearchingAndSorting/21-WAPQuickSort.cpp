#include<iostream>
#include<vector>
using namespace std;

void QuickSort(vector<int> &v,int low, int high)
{
    if(low>=high)
    {
        return;
    }
    int j=low;
    int i=low-1;
    int pivot=high;
    while(j<pivot)
    {
        if(v[j]<v[pivot])
        {
            i++;
            swap(v[i],v[j]);
        }
        j++;
    }
    i++;
    swap(v[i],v[pivot]);

    pivot=i;

    QuickSort(v,low,pivot-1);
    QuickSort(v,pivot+1,high);
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
    int low=0;
    int high=n-1;
    QuickSort(v,low,high);

    for(auto val: v)
    {
        cout<<val<<" ";
    }

}