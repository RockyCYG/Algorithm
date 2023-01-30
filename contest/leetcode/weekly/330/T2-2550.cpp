#include <bits/stdc++.h>

class Solution {
public:
    const int MOD = 1e9 + 7;
    int monkeyMove(int n) {
        return (fast_pow(2, n) - 2 + MOD) % MOD;
    }

    long long fast_pow(long long x, long long n) {
        long long res = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                res = (res * x) % MOD;
            }
            x = (x * x) % MOD;
        }
        return res;
    }
};