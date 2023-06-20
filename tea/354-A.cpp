// Problem: A. Vasya and Robot
// Contest: Codeforces - Codeforces Round 206 (Div. 1)
// URL: https://codeforces.com/problemset/problem/354/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    int n, l, r, Ql, Qr;
    cin >> n >> l >> r >> Ql >> Qr;
    vector<int> w(n);
    int pre = 0, suf = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        suf += w[i];
    }
    int ans = suf * r + (n - 1) * Qr;
    for (int i = 0; i < n; i++) {
        pre += w[i];
        suf -= w[i];
        int cost = pre * l + suf * r;
        int cl = i + 1, cr = n - i - 1;
        if (cl + 1 < cr) {
            cost += (cr - cl - 1) * Qr;
        } else if (cr + 1 < cl) {
            cost += (cl - cr - 1) * Ql;
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
    return 0;
}