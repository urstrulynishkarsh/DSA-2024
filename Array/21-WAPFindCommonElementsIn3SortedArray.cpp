#include<iostream>
#include<vector>
#include<set>
#include<limits.h>
using namespace std;



void DuplicateInArray(vector<int>& v1,vector<int>& v2,vector<int>& v3,int &n1,int &n2, int &n3,vector<int> &ans) {

            set<int> st;
            int i=0;
            int j=0;
            int k=0;
            while(i<n1 && j<n2 && k<n3)
            {
             if(v1[i]==v2[j] && v2[j]==v3[k] && v3[k]==v1[i])
                {
                    st.insert(v1[i]);
                    i++;
                    j++;
                    k++;
                }
                 else if(v1[i]<v2[j])
                {
                    i++;
                }
                else if(v2[j]<v3[k])
                {
                    j++;
                }
                else
                {
                    k++;
                }
                
            }
            for(auto it:st)
            {
                ans.push_back(it);
            }
           
}




    int main()
{
    int n1;
    cout<<"Enter the first size of array: ";
    cin>>n1;
    vector<int> v1(n1);
    cout<<"Enter the element in the first array: ";
    for(int i=0;i<n1;i++)
    {
        cin>>v1[i];
    }
     int n2;
    cout<<"Enter the second size of array: ";
    cin>>n2;
    vector<int> v2(n2);
    cout<<"Enter the element in the second array: ";
    for(int i=0;i<n2;i++)
    {
        cin>>v2[i];
    }
     int n3;
    cout<<"Enter the third size of array: ";
    cin>>n3;
    vector<int> v3(n3);
    cout<<"Enter the element in the third array: ";
    for(int i=0;i<n3;i++)
    {
        cin>>v3[i];
    }
   vector<int> ans;
   DuplicateInArray(v1,v2,v3,n1,n2,n3,ans);

   for(auto ele:ans)
   {
    cout<<ele<<" ";
   }
   
    
}