#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int> &arr)
{
    for(int i=0;i<arr.size()-1;i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[j]<arr[i])
                {
                    swap(arr[i],arr[j]);
                }
            }
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