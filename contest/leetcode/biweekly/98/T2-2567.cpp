#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min(nums[n - 3] - nums[0], min(nums[n - 2] - nums[1], nums[n - 1] - nums[2]));
    }
};