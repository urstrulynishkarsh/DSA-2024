#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;


bool isSafe(int i, int j,int row, int col,vector<vector<int> > &Maze,vector<vector<bool> > &visited )
{
    if((i>=0 && i<row) &&(j>=0 && j<col) && Maze[i][j]==1 && visited[i][j]==false)
    {
        return true;
    }
    return false;
}

void Solve(vector<vector<int> > &Maze, int row, int col,   int i, int j, vector<vector<bool> > &visited,vector<string> &path,string output)
{
    // base case
    if(i==row-1 && j==col-1)
    {
        path.push_back(output);
        return;
    }

    // down
    if(isSafe(i+1,j,row,col,Maze,visited))
    {
        visited[i][j]=true;
        Solve(Maze,row,col,i+1,j,visited,path,output+"D");
        visited[i][j]=false;

    }   

    // up
    if(isSafe(i-1,j,row,col,Maze,visited))
    {
         visited[i][j]=true;
        Solve(Maze,row,col,i-1,j,visited,path,output+"U");
        visited[i][j]=false;
    }

    // left
    if(isSafe(i,j-1,row,col,Maze,visited))
    {
         visited[i][j]=true;
        Solve(Maze,row,col,i,j-1,visited,path,output+"L");
        visited[i][j]=false;
    }

    // right
    if(isSafe(i,j+1,row,col,Maze,visited))
    {
         visited[i][j]=true;
        Solve(Maze,row,col,i,j+1,visited,path,output+"R");
        visited[i][j]=false;
    }



}


int main()
{
    int row,col;
    cout<<"Enter the row and col: ";
    cin>>row>>col;

    vector<vector<int> > Maze(row, vector<int>(col));
    cout<<"Enter the element in the Maze: ";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>Maze[i][j];
        }
    }

    if(Maze[0][0]==0)
    {
        cout<<"NoPathExit";
        return 0;
    }


    vector<vector<bool> >visited(row,vector<bool>(col,false));
    visited[0][0]=true;
    vector<string> path;
    string output;

    int i=0;
    int j=0;

    Solve(Maze,row,col,i,j,visited,path,output);

    for(auto val: path)
    {
        cout<<val<<" ";
    }



}