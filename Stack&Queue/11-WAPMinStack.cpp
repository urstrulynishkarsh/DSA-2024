#include<iostream>
using namespace std;
class MinStack {
public:
   vector<pair<int,int> > st;
    MinStack() {
        
    }
 
    void push(int val) {
        if(st.empty())
        {
            pair<int,int> p=make_pair(val,val);
            st.push_back(p);
        }
        else
        {
            pair<int,int> p;
            p.first=val;
            p.second=min(val,st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};
int main()
{
    MinStack minStack;

    // Push some values to the stack
    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(8);

    // Display top element
    std::cout << "Top element: " << minStack.top() << std::endl;

    // Display minimum element
    std::cout << "Minimum element: " << minStack.getMin() << std::endl;

    // Pop one element
    minStack.pop();

    // Display top element after pop
    std::cout << "Top element after pop: " << minStack.top() << std::endl;

    // Display minimum element after pop
    std::cout << "Minimum element after pop: " << minStack.getMin() << std::endl;

    return 0;
}
