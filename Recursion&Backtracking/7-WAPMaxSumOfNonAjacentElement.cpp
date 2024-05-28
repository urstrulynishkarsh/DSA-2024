 #include<iostream>
#include<vector>
#include<limits.h>
using namespace std;       
        
        
        
int MaximumSumOfNonAdjacent(vector<int> &v, int n, int i)
{
    if(i>=n)
    {
        return 0;
    }
    int include=MaximumSumOfNonAdjacent(v,n,i+2)+v[i];
    int exclude=MaximumSumOfNonAdjacent(v,n,i+1)+0;
    return max(include,exclude);
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
    int index=0;
    cout<<MaximumSumOfNonAdjacent(v,n,index);

}