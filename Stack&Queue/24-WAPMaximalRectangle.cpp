#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
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
    int maximalRectangle(vector<vector<char> >& matrix) {
        vector<vector<int> > v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<m;j++)
            {
                temp.push_back(matrix[i][j]-'0');
            }
            v.push_back(temp);
        }
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j])
                {
                    v[i][j]+=v[i-1][j];
                }
                else{
                    v[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(v[i]));
        }
        return area;
    }

int main()
{
    int row,col;
    cout<<"Enter the row and Column of a matrix: ";
    cin>>row>>col;

    vector<vector<char> > matrix(row, vector<char>(col));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout<<maximalRectangle(matrix);

    
}