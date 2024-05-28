#include<iostream>
#include<vector>
#include<stack>
using namespace std;

 vector<int> previousSmallerElement(vector<int>& heights)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for(int i=0;i<heights.size();i++)
        {
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
      vector<int> nextSmallerElement(vector<int>& heights)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for(int i=heights.size()-1;i>=0;i--)
        {
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev=previousSmallerElement(heights);
        vector<int> next=nextSmallerElement(heights);
        int size=heights.size();
        int maxArea=INT_MIN;
        for(int i=0;i<size;i++)
        {
            int length=heights[i];
            if(next[i]==-1)
            {
                next[i]=size;
            }
            int width=next[i]-prev[i]-1;
            int area=length*width;
            maxArea=max(area,maxArea);
        }
        return maxArea;
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

    cout<<largestRectangleArea(v);
}