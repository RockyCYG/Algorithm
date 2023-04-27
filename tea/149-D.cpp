#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;
int dp[700][700][3][3];

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> st;
    vector<int> right(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push_back(i);
        } else {
            right[st.back()] = i;
            st.pop_back();
        }
    }
    for (int l = 0; l < n; l++) {
        for (int r = 0; r < n; r++) {
            for (int lc = 0; lc < 3; lc++) {
                for (int rc = 0; rc < 3; rc++) {
                    dp[l][r][lc][rc] = -1;
                }
            }
        }
    }
    function<int(int, int, int, int)> f = [&](int l, int r, int lc, int rc) -> int {
        if (l > r) {
            return 1;
        }
        if (dp[l][r][lc][rc] >= 0) {
            return dp[l][r][lc][rc];
        }
        int mid = right[l];
        i64 res = 0LL;
        if (mid < r) {
            res = (res + 1LL * f(l + 1, mid - 1, 0, 1) * f(mid + 1, r, 1, rc)) % MOD;
            res = (res + 1LL * f(l + 1, mid - 1, 0, 2) * f(mid + 1, r, 2, rc)) % MOD;
            if (lc != 1) {
                res = (res + 1LL * f(l + 1, mid - 1, 2, 0) * f(mid + 1, r, 0, rc)) % MOD;
            }
            if (lc != 2) {
                res = (res + 1LL * f(l + 1, mid - 1, 1, 0) * f(mid + 1, r, 0, rc)) % MOD;
            }
        } else {
            if (lc != 1) {
                res = (res + f(l + 1, r - 1, 1, 0)) % MOD;
            }
            if (lc != 2) {
                res = (res + f(l + 1, r - 1, 2, 0)) % MOD;
            }
            if (rc != 1) {
                res = (res + f(l + 1, r - 1, 0, 2)) % MOD;
            }
            if (rc != 2) {
                res = (res + f(l + 1, r - 1, 0, 1)) % MOD;
            }
        }
        return dp[l][r][lc][rc] = res;
    };
    cout << f(0, n - 1, 0, 0) << '\n';
    return 0;
}