#include <vector>

using namespace std;

class Fancy {
public:
    Fancy() {
        // pass
    }
    
    void append(int val) {
        nums.push_back(val);
        multArr.push_back(M);
        addArr.push_back(A);
    }
    
    void addAll(int inc) {
        A = (A + inc) % mod;
    }
    
    void multAll(int m) {
        M = M * m % mod;
        A = A * m % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        long long M1_ni = niyuan(multArr[idx]);
        long long res = nums[idx] * M % mod * M1_ni % mod;
        res = (res + A - addArr[idx] * M % mod * M1_ni % mod + mod) % mod;
        return res;
    }
private:
    long long mod = 1e9 + 7;
    vector<long long> nums;
    vector<long long> multArr, addArr;
    long long M = 1, A = 0;

    long long niyuan(long long x) {
        // 使用费马小定理，计算 x 在 mod p 运算下的逆元
        // 理论上逆元为 x ^ (p - 2)
        // 这里计算 x ^ (p - 2) 使用了二进制的方法加速
        long long res = 1ll, p = mod - 2;
        while (p) {
            if (p & 1ll) res = res * x % mod;
            x = x * x % mod;
            p >>= 1;
        }
        return res;
    }
};
