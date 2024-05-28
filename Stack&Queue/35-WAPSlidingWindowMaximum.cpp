#include<iostream>
#include<vector>
#include<deque>
using namespace std;


vector<int> SlidingWindowMaximum(vector<int> &v, int k)
{
    // make a deque
    deque<int> dq;

    vector<int> ans;
    
    // process first k window element
    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && v[i]>=v[dq.back()])
        {
            dq.pop_back();
        }
        // inserting index;
        dq.push_back(i);
    }
    ans.push_back(v[dq.front()]);
    for(int i=k;i<v.size();i++)
    {
        if(!dq.empty() && i-dq.front()>=k)
        {
            dq.pop_front();
        }
        // choote element ko hatao
        while(!dq.empty() && v[i]>=v[dq.back()] )
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(v[dq.front()]);
    }

    return ans;

}

int main(){
     int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int k;
    cout<<"Enter the size of the window: ";
    cin>>k;
    vector<int> ans=SlidingWindowMaximum(v,k);
    for(auto val:ans)
    {
        cout<<val<<' ';
    }
}