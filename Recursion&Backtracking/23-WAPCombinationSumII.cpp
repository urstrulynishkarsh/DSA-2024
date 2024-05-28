#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

void Solve(vector<int>& candidates, int target,int index,vector<vector<int> > &result,vector<int> &ans)
    {   

        if(target==0)
        {
            result.push_back(ans);
            return;
        }
        if(target<0)
        {
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1])
            continue;
            ans.push_back(candidates[i]);
            Solve(candidates,target-candidates[i],i+1,result,ans);
            ans.pop_back();
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
    int target;
    cout<<"Enter the Target: ";
    cin>>target;
    sort(v.begin(),v.end());
    vector<vector<int> >result;
    vector<int> ans;
    Solve(v,target,0,result,ans);

    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }


}