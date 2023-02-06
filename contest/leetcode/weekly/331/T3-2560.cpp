#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        auto check = [&](int x) -> bool {
            int f0 = 0, f1 = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] > x) {
                    f0 = f1;
                } else {
                    int t = f1;
                    f1 = max(f1, f0 + 1);
                    f0 = t;
                }
            }
            return f1 >= k;
        };
        int lo = 0, hi = 1E9 + 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};