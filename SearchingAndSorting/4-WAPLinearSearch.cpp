#include<iostream>
#include<vector>
using namespace std;

int LinearSearch(vector<int> &v,int &target)
{
    
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==target)
        {
            return i;
        }
    }
    return -1;
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
    int target;
    cout<<"Enter the seach element: ";
    cin>>target;
    cout<<LinearSearch(v,target);
}