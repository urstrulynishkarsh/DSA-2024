#include<iostream>
#include<vector>
using namespace std;


int FindPivotElement(vector<int> &nums)
{
	   int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (nums[mid] > nums[mid + 1] && mid + 1 < nums.size())
        {
            return mid;
        }
        if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]  )
        {
            return mid - 1;
        }
        if (nums[s] >= nums[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
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