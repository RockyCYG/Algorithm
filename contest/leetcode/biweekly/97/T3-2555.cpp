#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        int left = 0;
        vector<int> pre(n + 1);
        int ans = 0;
        for (int right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) {
                left++;
            }
            ans = max(ans, right - left + 1 + pre[left]);
            pre[right + 1] = max(pre[right], right - left + 1);
        }
        return ans;
    }
};