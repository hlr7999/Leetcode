#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    // can not change s to t
    if (s.size() != t.size()) {
        cout << -1;
        return 0;
    }
    vector<int> cnt(26, 0);
    for (int i = 0; i < s.size(); ++i) {
        ++cnt[s[i] - 'a'];
        --cnt[t[i] - 'a'];
    }
    for (int i : cnt) {
        if (i != 0) {
            cout << -1;
            return 0;
        }
    }
    // can change s to t
    int si = 0, ti = 0, step = 0;
    while (si < s.size()) {
        if (s[si] == t[ti]) {
            ++ti;
        } else {
            ++step;
        }
        ++si;
    }
    cout << step;
    return 0;
}