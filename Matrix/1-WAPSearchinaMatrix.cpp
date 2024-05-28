#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int x) {
          int s = 0;
    int totalsize =matrix.size()*matrix[0].size();
    int e = totalsize - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int rowindex = mid /matrix[0].size() ;
        int colindex = mid % matrix[0].size();

        if (matrix[rowindex][colindex] == x)
        {
            return true;
        }

        if (matrix[rowindex][colindex] > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return false;
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
    int target;
    cout<<"Enter the target value: ";
    cin>>target;
    cout<<searchMatrix(matrix,target);
}