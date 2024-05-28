#include<iostream>
#include<vector>
using namespace std;
void ReverseArray(vector<int> &v)
{
    int s=0;
    int e=v.size()-1;
    while(s<=e)
    {
        swap(v[s++],v[e--]);
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
    ReverseArray(v);
    for(auto value:v)
    {
        cout<<value<<" ";
    }
}