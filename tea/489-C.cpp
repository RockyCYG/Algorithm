// Problem: C. Given Length and Sum of Digits...
// Contest: Codeforces - Codeforces Round 277.5 (Div. 2)
// URL: https://codeforces.com/problemset/problem/489/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

pair<string, string> solve() {
    int m, s;
    cin >> m >> s;
    string ans_max(m, '0');
    string ans_min(m, '0');
    if (s == 0) {
        if (m == 1) {
            return {"0", "0"};
        } else {
            return {"-1", "-1"};
        }
    }
    if (9 * m < s) {
        return {"-1", "-1"};
    }
    int x = s;
    int i = m - 1;
    for (; i >= 0 && x >= 9; i--, x -= 9) {
        ans_min[i] = '9';
    }
    if (i > 0) {
        ans_min[i] = x - 1 + '0';
        ans_min[0] = '1';
    } else {
        ans_min[0] = x + '0';
    }
    x = s;
    i = 0;
    for (; i < m && x >= 9; i++, x -= 9) {
        ans_max[i] = '9';
    }
    if (i < m) {
        ans_max[i] = x + '0';
    }
    return {ans_min, ans_max};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pair<string, string> ans = solve();
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}