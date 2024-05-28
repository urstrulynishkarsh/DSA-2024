#include<iostream>
#include<vector>
using namespace std;

bool isIdealPermutation(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        if(abs(v[i]-i)>1)
        {
            return false;
        }
    }
    return true;
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
    cout<<isIdealPermutation(v);

}