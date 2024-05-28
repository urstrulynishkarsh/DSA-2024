#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;


vector<int> InterleaveQueue(queue<int> &q){
    vector<int> ans;
    int n=q.size();
   vector<int> arr(n,0);

  int i=0;
       while(!q.empty())
       {
           arr[i]=q.front();
           q.pop();
           i++;
       }
    int half=n/2;
    for(int i=0;i<half;i++)
    {
        ans.push_back(arr[i]);
        ans.push_back(arr[half+i]);
    }
    return ans;
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);  
    q.push(8);
    // q.push(10);
    
    vector<int> ans=InterleaveQueue(q);

    for(auto val:ans)
    {
        cout<<val<<" ";
    }

}