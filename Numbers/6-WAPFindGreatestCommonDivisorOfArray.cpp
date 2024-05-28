#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int GCD( vector<int> &v){
    int small=*min_element(v.begin(),v.end());
    int large=*max_element(v.begin(),v.end());

    if(small==0)
    {
        return large;
    }
    if(large==0)
    {
        return small;
    }
    while(small>0 && large>0)
    {
        if(small>large)
        {
            small-=large;
        }
        else{
            large-=small;
        }
    }
    return small==0?large:small;
}

int main(){
      int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<GCD(v);
}