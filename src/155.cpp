#include <stack>

using namespace std;

// in this problem, u can use two stacks
// one of them is used to store the min value
// or u can use only one stack, in that case
// u should push the old min to the stack when x <= min
class MinStack {
private:
    int _min = INT_MAX;
    stack<int> st;

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        // if x <= min, push min to the stack before x
        if (x <= _min) {
            st.push(_min);
            _min = x;
        }
        st.push(x);
    }
    
    void pop() {
        if (st.top() == _min) {
            st.pop();
            _min = st.top();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return _min;
    }
};