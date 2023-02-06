#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s;
        for (int x : banned) {
            s.insert(x);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i > maxSum) {
                break;
            }
            if (s.find(i) == s.end()) {
                maxSum -= i;
                ans++;
            }
        }
        return ans;
    }
};