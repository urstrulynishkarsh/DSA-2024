#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) 
    {
        // step1: create a Stack
        stack<int> st;
        
        // step2:put all index inside the stack
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        
        // Step3: find one person while the stack size 1
        
        while(st.size()!=1)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            // that means a know b
            if(M[a][b])
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        int mightBeCelebrity=st.top();
        st.pop();
        
        // Step4: chck that actual person is celebrity or not
        
        // check row wise
        for(int i=0;i<n;i++)
        {
            if(M[mightBeCelebrity][i]!=0)
            {
                return -1;
            }
        }
        // check column wise
        for(int i=0;i<n;i++)
        {
            // i!=mightBeCelebrity.  this is used to exclude diagonal zero
            if(M[i][mightBeCelebrity]==0 && i!=mightBeCelebrity)
            {
                return -1;
            }
        }
        
        return mightBeCelebrity;
        
      
    }


int main()
{
    int n;
    cout<<"Enter the size for N*N of a matrix: ";
    cin>>n;

    vector<vector<int> > matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout<<celebrity(matrix,n);
    
}