#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int FindMax(vector<vector<int> >& matrix) {

    int maxi=INT_MIN;
     int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
           maxi=max(maxi,matrix[i][j]);
        }
    }
    return maxi;
    
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
    cout<<FindMax(matrix);
}