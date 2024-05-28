#include<iostream>
#include<vector>
using namespace std;

void PrintSolution( vector<vector<int> > &Board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<Board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row,int col,vector<vector<int> > &Board,int n)
{

     // cheking row
    int i=row;
    int j=col;
    while(j>=0)
    {
        if(Board[i][j]==1)
        {
            return false;
        }
        j--;
    }

    // check upper left diagonal
    i=row;
    j=col;
    while(i>=0 && j>=0)
    {
        if(Board[i][j]==1)
        {
            return false;
        }
        i--;
        j--;
    }

    // check botom left diagonal

    i=row;
    j=col;
    while(i<n && j>=0)
    {
        if(Board[i][j]==1)
        {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
    
}

void Solve( vector<vector<int> > &Board,int col,int n)
{
    // base case
    if(col>=n)
    {
        PrintSolution(Board,n);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,Board,n))
        {
            Board[row][col]=1;
            Solve(Board,col+1,n);
            // backtracking
             Board[row][col]=0;   //empty cell
        }
        
    }
}

int main(){
    int n;
    cout<<"Enter the number for square type matrix: ";
    cin>>n;
    vector<vector<int> > Board(n,vector<int> (n,0));
    int col=0;
    Solve(Board,col,n);

}