#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    map<char, char> mp;
    mp['('] = ')';
    mp['['] = ']';
    mp['{'] = '}';
    for (auto& c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            char preC = st.top();
            st.pop();
            if (mp[preC] != c) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {

}