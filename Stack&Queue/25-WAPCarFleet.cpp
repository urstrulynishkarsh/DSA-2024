#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// important part
class Car{
    public:
    int pos;
    int speed;
    Car(int p, int s)
    {
        this->pos=p;
        this->speed=s;
    }

};

static bool mycmp(Car &a,Car &b)
{
    return a.pos<b.pos;
}
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<Car> cars;
    for(int i=0;i<position.size();i++)
    {
        Car car(position[i],speed[i]);
        cars.push_back(car);
    }
    sort(cars.begin(),cars.end(),mycmp);
     for(auto val:cars)
   {
    cout<<val.pos<<" ";
   }
   cout<<endl;
    for(auto val:cars)
   {
    cout<<val.speed<<" ";
   }
   cout<<endl;

   stack<float> st;
   for(auto val:cars)
   {
        float time=(target-val.pos)/(float)val.speed;
        while(!st.empty() && time>=st.top())
        {
            st.pop();
        }
        st.push(time);
   }
   return st.size();
}
int main()
{
    int target;
    cout<<"Enter the target number line: ";
    cin>>target;
    int n;
    cout<<"Enter the the size for position and speed array: ";
    cin>>n;
    vector<int> position(n);
    cout<<"Enter the element in the position array: ";
    for(int i=0;i<n;i++)
    {
        cin>>position[i];
    }
    vector<int> speed(n);
    cout<<"Enter the element in the speed array: ";
    for(int i=0;i<n;i++)
    {
        cin>>speed[i];
    }
    cout<<carFleet(target,position,speed);


}