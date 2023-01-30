#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int great[4000][4001];
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int less[n + 1];
        memset(less, 0, sizeof(less));
        for (int k = n - 2; k >= 2; k--) {
            memcpy(great[k], great[k + 1], sizeof(great[k + 1]));
            for (int x = nums[k + 1] - 1; x > 0; x--) {
                great[k][x]++;
            }
        }
        long long ans = 0l;
        for (int j = 1; j < n - 2; j++) {
            for (int x = nums[j - 1] + 1; x <= n; x++) {
                less[x]++;
            }
            for (int k = j + 1; k < n - 1; k++) {
                if (nums[j] > nums[k]) {
                    ans += less[nums[k]] * great[k][nums[j]];
                }
            }
        }
        return ans;
    }
};