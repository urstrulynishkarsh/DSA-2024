#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void  SpiralMatrix(vector<vector<int> >& matrix,int row,int col, vector<int> &ans) {

    int totalelement=row*col;
    int count=0;
    int startingrow=0;
    int startingcol=0;
    int endingrow=row-1;
    int endingcol=col-1;
    while(count<totalelement)
    {
        for(int i=startingcol;i<=endingcol && count<totalelement;i++)
        {
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;

        for(int i=startingrow;i<=endingrow && count<totalelement;i++)
        {
            ans.push_back(matrix[i][endingcol]);
            count++;
        }
        endingcol--;

        for(int i=endingcol;i>=startingcol && count<totalelement;i--)
        {
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;


        for(int i=endingrow;i>=startingrow && count<totalelement;i--)
        {
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
    }

    
}


int main()
{
    int row,col;
    cout<<"Enter the row and Column of a matrix: ";
    cin>>row>>col;

    vector<vector<int> > matrix(row, vector<int>(col));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans;
    SpiralMatrix(matrix,row,col,ans);
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
}