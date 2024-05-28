#include<iostream>
#include<vector>
using namespace std;

 int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // kitni petrol kam pad agya
    int deficiency=0;
    // kitna petrol bacha hua hai
    int balance=0;
    int start=0;
    for(int i=0;i<gas.size();i++)
    {
        balance+=gas[i]-cost[i];
        if(balance<0)
        {
            // may be yahan galti hogi
            deficiency+=balance;
            start=i+1;
            balance=0;
        }
    }
    if(deficiency+balance>=0)
    {
        return start;
    }
    else{
        return -1;
    }

 }
int main(){
    int n;
    cout<<"Enter the size of gas and cost array: ";
    cin>>n;
    vector<int> gas(n);
    cout<<"Enter the element in the gas array: ";
    for(int i=0;i<n;i++)
    {
        cin>>gas[i];
    }
       vector<int> cost(n);
    cout<<"Enter the element in the cost array: ";
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    cout<<canCompleteCircuit(gas,cost);
}