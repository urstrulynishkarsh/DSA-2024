#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;

bool isPrime(int n)
{
    if(n<=1)
    {
        return false;
    }
    if(n==2 ||n==3)
    {
        return true;
    }
    if(n%2==0 || n%3==0)
    {
        return false;
    }

    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0 ||n%(i+2)==0)
        {
            return false;
        }
    }
    return true;
}

void largestPrimeInArray(vector<int> &arr)
{
    int maxElement=*max_element(arr.begin(),arr.end());
    vector<bool> prime(maxElement+1,true);
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=maxElement;i++)
    {
        if(prime[i]==true)
        {
            int j=i*2;
            while(j<=maxElement)
            {
                prime[j]=false;
                j+=i;
            }
        }
    }
    int mini=INT_MAX;
    int maxi=INT_MIN;

    for(int i=0;i<arr.size();i++)
    {
        if(prime[arr[i]])
        {
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
        }
    }
      cout << "Minimum : " << mini << endl;
    cout << "Maximum : " << maxi << endl;


}

int main()
{
    int n;
    cin>>n;
     vector<int> arr(n);
     for(int i=0;i<n;i++)
     {
        cin>>arr[i];
     }
     largestPrimeInArray(arr);
}