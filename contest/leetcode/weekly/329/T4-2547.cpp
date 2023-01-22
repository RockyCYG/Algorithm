#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n + 1];
        f[0] = 0;
        int hash[n];
        for (int i = 0; i < n; i++) {
            memset(hash, 0, sizeof(hash));
            int t = 0, res = INT_MAX;
            for (int j = i; j >= 0; j--) {
                int x = nums[j];
                if (++hash[x] == 2) {
                    t += 2;
                } else if (hash[x] > 2) {
                    t++;
                }
                res = min(res, f[j] + t);
            }
            f[i + 1] = k + res;
        }
        return f[n];
    }
};