#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int> &arr)
{
    for(int i=1;i<arr.size();i++)
        {
            // fetch the value
            int value=arr[i];
            int j=i-1;
            for(;j>=0;j--)
            {
                // comparision
                if(arr[j]>value)
                {
                    // shifiting
                    arr[j+1]=arr[j];
                }
                else
                {
                    break;
                }
            }
            // copy the value
            arr[j+1]=value;
        }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
   
    SelectionSort(v);

    for(auto val:v)
    {
        cout<<val<<" ";
    }
}