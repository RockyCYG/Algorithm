#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> cnt;
        int n = basket1.size();
        for (int i = 0; i < n; i++) {
            cnt[basket1[i]]++;
            cnt[basket2[i]]--;
        }
        vector<int> a;
        vector<int> b;
        int mn = INT_MAX;
        for (auto [x, c] : cnt) {
            mn = min(mn, x);
            if (c % 2) {
                return -1;
            }
            if (c > 0) {
                for (int i = 0; i < c / 2; i++) {
                    a.push_back(x);
                }
            } else {
                for (int i = 0; i < -c / 2; i++) {
                    b.push_back(x);
                }
            }
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        long long ans = 0LL;
        int k = a.size();
        for (int i = 0; i < k; i++) {
            ans += min(min(a[i], b[i]), mn * 2);
        }
        return ans;
    }
};