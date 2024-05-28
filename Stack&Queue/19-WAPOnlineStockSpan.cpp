#include<iostream>
#include <stack>
#include <utility>

class StockSpanner {
public:
    std::stack<std::pair<int, int> > st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span});
        
        return span;
    }
};

// Example usage:
int main() {
    StockSpanner spanner;
    int result1 = spanner.next(100);
    int result2 = spanner.next(80);
    int result3 = spanner.next(60);
    int result4 = spanner.next(70);
    // Use results as needed...
    return 0;
}
