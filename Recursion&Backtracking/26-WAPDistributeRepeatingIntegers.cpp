#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<unordered_map>
using namespace std;

bool solve(vector<int>& counts, vector<int>& quantity, int customer){
        //base case
        if(customer >= quantity.size()){
            return true;
        }

        for(int i=0; i<counts.size(); i++){
            if(counts[i] >= quantity[customer]){
                counts[i] -= quantity[customer];
                if(solve(counts, quantity, customer+1)){
                    return true;
                }
                counts[i] += quantity[customer];
            }
        }

        return false;
    }



int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int m;
    cout<<"Enter the size of Quantity array: ";
    cin>>m;

    vector<int> quantity(m);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<m;i++)
    {
        cin>>quantity[i];
    }

      unordered_map<int, int> mp;
        for(auto it : v){
            mp[it]++;
        }

        vector<int> counts;
        for(auto it : mp){
            counts.push_back(it.second);
        }

        sort(quantity.rbegin(), quantity.rend());
        int customer = 0;
        cout<<solve(counts, quantity, customer);



}