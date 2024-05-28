#include<iostream>
#include<vector>
#include<deque>
using namespace std;


int Minmaxofsubarrayk(vector<int> &v, int k)
{
    // make a deque
    deque<int> dq,dq2;

    int ans=0;
    
    // process first k window element
    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && v[i]>=v[dq.back()])
        {
            dq.pop_back();
        }
         while(!dq2.empty() && v[i]<=v[dq2.back()])
        {
            dq2.pop_back();
        }
        // inserting index;
        dq.push_back(i);
        dq2.push_back(i);
    }
    ans+=v[dq.front()]+v[dq2.front()];
    for(int i=k;i<v.size();i++)
    {
        if(!dq.empty() && i-dq.front()>=k)
        {
            dq.pop_front();
        }
        if(!dq2.empty() && i-dq2.front()>=k)
        {
            dq2.pop_front();
        }
        // choote element ko hatao
        while(!dq.empty() && v[i]>=v[dq.back()] )
        {
            dq.pop_back();
        }
          while(!dq2.empty() && v[i]<=v[dq2.back()])
        {
            dq2.pop_back();
        }
        dq.push_back(i);
         dq2.push_back(i);
        ans+=v[dq.front()]+v[dq2.front()];
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
  cout<<Minmaxofsubarrayk(v,k);
    
}