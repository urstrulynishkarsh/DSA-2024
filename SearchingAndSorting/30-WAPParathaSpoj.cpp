#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool possibleSolution(vector<int> &v,int m,int solution)
{
    int currentParatha=0;
    for(int i=0;i<v.size();i++)
    {
        int r=v[i];
        int j=1;
        int timetaken=0;
        while (true)
        {
            if(timetaken+r*j<=solution)
            {
                ++currentParatha;
                timetaken+=j*r;
                ++j;
            }
            else{
                break;
            }
            /* code */
        }
        if(currentParatha>=m)
        {
            return true;
        }
        

    }
    return false;
}


int ParathaSpoj(vector<int> &v,int NP)
{
    // sort(v.begin(),v.end());
    int s=0;
    int highestRank=*max_element(v.begin(),v.end());
    int e=highestRank*(NP*(NP+1)/2);
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(possibleSolution(v,NP,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
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
    int NP;
    cout<<"Enter the number of paratha : ";
    cin>>NP;
    cout<<ParathaSpoj(v,NP);
}