#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

bool isSafe(int row, int col,vector<vector<char> > &Board, char value)
{
    int n =Board.size();
    // row check
    for(int i=0;i<n;i++)
    {
        if(Board[row][i]==value)
        {
            return false;
        }
        if(Board[i][col]==value)
        {
            return false;
        }
        if(Board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==value)
        {
            return false;
        }
    }
    return true;

}

bool Sudoku(vector<vector<char> > &Board)
{
    int n=Board.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Board[i][j]=='.')
            {
                // now we are filling inside the value 1 to 9
                for(char value='1';value<='9';value++)
                {
                    if(isSafe(i,j,Board,value))
                    {
                        Board[i][j]=value;
                        bool NextSolution=Sudoku(Board);
                        if(NextSolution==true)
                        {
                        return true;
                        }
                        else
                        {
                        Board[i][j]='.';
                        }

                    }
                }
                return false;

            }      

        }
    }
    return  true;

}
int main()
{
    int n;
    cout<<"Enter the size of a Sudoku: ";
    cin>>n;

    vector<vector<char> > Board(n,vector<char>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>Board[i][j];
        }
    }   
    Sudoku(Board);

     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<Board[i][j]<<" ";
        }
        cout<<endl;
    } 









}