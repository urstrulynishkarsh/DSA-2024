#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void WavePrint(vector<vector<int> >& matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i=0;i<cols;i++)
    {
        if((i&1)==0){
            for(int j=0;j<rows;j++)
            {
                cout<<matrix[j][i];
            }
        }
        else{
            for(int j=rows-1;j>=0;j--)
            {
                cout<<matrix[j][i];
            }
        }
        
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
    WavePrint(matrix);
}