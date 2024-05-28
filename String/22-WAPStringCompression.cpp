#include<iostream>
#include<cstring>
#include<string.h>
#include<limits.h>
#include<vector>
using namespace std;

int StringCompression(vector<char> &chars)
{
    vector<char>ans;
    int n=chars.size();
    for(int i=0;i<n;i++)
    {
        int count=1;
        while(i<n-1 && chars[i]==chars[i+1])
        {
            count++;
            i++;
        }
        ans.push_back(chars[i]);
        if(count>1)
        {
            for(char c:to_string(count))
            {
                ans.push_back(c);
            }
        } 
    }
    chars=ans; 
      // important line i was  forget in this  case
    for(auto val: ans)
    {
        cout<<val<<' ';
        cout<<endl;
    }
  
    return ans.size();
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<char> chars(n);

    cout<<"Enter the element in the array: ";
    while(n--)
    {
        char ch;
        cin>>ch;
        chars.push_back(ch);
    }

    cout<<StringCompression(chars);
}