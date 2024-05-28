#include<iostream>
#include<vector>
using namespace std;

int main(){
    int A,B,C;
    cout<<"Enter the value of A, B and C: ";
    cin>>A>>B>>C;

    int maxi=0;
    int mini=0;
    int mid=A+B+C;
    maxi=max(max(A,B),C);
    mini=min(min(A,B),C);
    cout<<mid-maxi-mini;

}