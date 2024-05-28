#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int FindMin(vector<vector<int> >& matrix) {

    int mini=INT_MAX;
     int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
           mini=min(mini,matrix[i][j]);
        }
    }
    return mini;
    
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
    cout<<FindMin(matrix);
}