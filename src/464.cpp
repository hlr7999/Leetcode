#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, bool> mp;
    vector<bool> used;
    int maxInt;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal)
            return false;
        if (desiredTotal <= 0) return true;
        used = vector<bool>(maxChoosableInteger + 1, false);
        maxInt = maxChoosableInteger;
        return canWin(desiredTotal);
    }
    bool canWin(int target) {
        if (target <= 0) return false;
        int index = usedToIndex();
        if (mp.find(index) == mp.end()) {
            for (int i = 1; i <= maxInt; ++i) {
                if (!used[i]) {
                    used[i] = true;
                    if (!canWin(target - i)) {
                        mp[index] = true;
                        used[i] = false;
                        return true;
                    }
                    used[i] = false;
                }
            }
            mp[index] = false;
        }
        return mp[index];
    }
    int usedToIndex() {
        int index = 0;
        for (bool b : used) {
            index <<= 1;
            if (b) index |= 1;
        }
        return index;
    }
};