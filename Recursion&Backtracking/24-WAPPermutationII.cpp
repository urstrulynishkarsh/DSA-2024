#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<unordered_map>
using namespace std;

void Permutation(vector<int>& nums,vector<vector<int> > &result, int index)
    {
        if(index>=nums.size())
        {
            result.push_back(nums);
            return;
        }
        unordered_map<int,bool> visited;
        for(int j=index;j<nums.size();j++)
        {
            if(visited.find(nums[j])!=visited.end())
            {
                continue;
            }
            visited[nums[j]]=true;
            swap(nums[index],nums[j]);
            Permutation(nums,result,index+1);
            swap(nums[index],nums[j]);

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
    vector<vector<int> >result;
    Permutation(v,result,0);

    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }


}