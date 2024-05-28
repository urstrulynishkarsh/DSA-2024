#include<iostream>
#include<string.h>
#include<string>
#include<queue>
using namespace std;

string FirstNonRepeating(string &input)
{
    string ans;
    int freq[26]={0};
    queue<char> q;
    for(char ch:input)
    {
        freq[ch-'a']++;
        q.push(ch);

        while(!q.empty())
        {
            if(freq[q.front()-'a']>1)
            {
                q.pop();
            }
            else{
                ans+=q.front();
                break;
            }
        }
        if(q.empty())
        {
            ans+='#';
        }
    }
    return ans;
}


int main()
{
    string input;
    cout<<"Enter the string: ";
    getline(cin,input);

    string ans=FirstNonRepeating(input);
    cout<<ans;
}