#include <vector>
#include <stack>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            st.push(nestedList[i]);
        }
    }

    int next() {
        int res = st.top().getInteger();
        st.pop();
        return res;
    }

    bool hasNext() {
        while (!st.empty()) {
            if (st.top().isInteger()) {
                return true;
            } else {
                vector<NestedInteger> sub = st.top().getList();
                st.pop();
                for (int i = sub.size() - 1; i >= 0; --i) {
                    st.push(sub[i]);
                }
            }
        }
        return false;
    }
};