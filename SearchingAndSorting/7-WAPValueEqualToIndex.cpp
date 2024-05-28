#include<iostream>
#include<vector>
using namespace std;


void valueEqualToIndex(vector<int> &arr,vector<int> &ans)
{
	    for(int i=0;i<arr.size();i++)
	    {
	        if(arr[i]==i+1)
	        {
	            ans.push_back(arr[i]);
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

      vector<int> ans;
      valueEqualToIndex(v,ans);

}