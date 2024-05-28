#include<iostream>
#include<vector>
using namespace std;


int FindPivotElement(vector<int> &arr)
{
	   int s=0;
       int e=arr.size()-1;
    
        if(arr[s]<arr[e])
        {
            return arr[s];
        }
        while(s<e)
        {
               int mid=s+(e-s)/2;
            if(arr[mid]>=arr[0])
            {
                s=mid+1;
            }
            else{
                e=mid;
            }

        }
        return arr[s];
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

      cout<<FindPivotElement(v);

}