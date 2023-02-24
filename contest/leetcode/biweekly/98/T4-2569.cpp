#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int MX = 4e5 + 1;

    int sum[MX << 2];
    bool flip[MX << 2];

    void maintain(int o) {
        sum[o] = sum[o * 2] + sum[o * 2 + 1];
    }

    void f(int o, int l, int r) {
        sum[o] = r - l + 1 - sum[o];
        flip[o] = !flip[o];
    }

    void build(vector<int>& a, int o, int l, int r) {
        if (l == r) {
            sum[o] = a[l - 1];
            return;
        }
        int m = (l + r) / 2;
        build(a, o * 2, l, m);
        build(a, o * 2 + 1, m + 1, r);
        maintain(o);
    }

    void update(vector<int>& a, int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            f(o, l, r);
            return;
        }
        int m = (l + r) / 2;
        if (flip[o]) {
            f(o * 2, l, m);
            f(o * 2 + 1, m + 1, r);
            flip[o] = false;
        }
        if (m >= L) {
            update(a, o * 2, l, m, L, R);
        }
        if (m < R) {
            update(a, o * 2 + 1, m + 1, r, L, R);
        }
        maintain(o);
    }

public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        build(nums1, 1, 1, n);
        long long s = accumulate(nums2.begin(), nums2.end(), 0LL);
        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                update(nums1, 1, 1, n, q[1] + 1, q[2] + 1);
            } else if (q[0] == 2) {
                s += 1LL * sum[1] * q[1];
            } else {
                ans.push_back(s);
            }
        }
        return ans;
    }
};