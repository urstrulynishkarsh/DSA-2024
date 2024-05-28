 #include<iostream>
#include<vector>
#include<limits.h>
using namespace std;       
        
        
        
int MinimumCostForTicket(vector<int> &day,vector<int> &cost, int i)
{
    if(i>=day.size())
    {
        return 0;
    }
    int cost1=cost[0]+MinimumCostForTicket(day,cost,i+1);

    int passEndDay=day[i]+7-1;
    int j=i;
    while(j<day.size() && day[j]<=passEndDay)  //day[j]
    {
        j++;
    }
    int cost2=cost[1]+MinimumCostForTicket(day,cost,j);
     passEndDay=day[i]+30-1;
    j=i;
    while(j<day.size() && day[j]<=passEndDay)
    {
        j++;
    }
    int cost3=cost[2]+MinimumCostForTicket(day,cost,j);

    return min(cost1,min(cost2,cost3));
}

    int main()
{
    int n;
    cout<<"Enter the size of Days array: ";
    cin>>n;
    vector<int> days(n);
    cout<<"Enter the element in Days array: ";
    for(int i=0;i<n;i++)
    {
        cin>>days[i];
    }
    vector<int> cost(3);
    cout<<"Enter the Element int the cost: ";
     for(int i=0;i<3;i++)
    {
        cin>>cost[i];
    }
    
    int index=0;
    cout<<MinimumCostForTicket(days,cost,index);

}