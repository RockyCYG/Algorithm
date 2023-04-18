// Problem: A. Division
// Contest: Codeforces - Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)
// URL: https://codeforces.com/problemset/problem/1444/A
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// Problem: C. RationalLee
// Contest: Codeforces - Codeforces Round 652 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1369/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 p, q;
    cin >> p >> q;
    if (p % q > 0) {
        cout << p << '\n';
        return;
    }
    set<pair<i64, i64>> s;
    i64 x = p, y = q;
    for (int i = 2; i * i <= q; i++) {
        i64 t = 1;
        while (y % i == 0) {
            y /= i;
            t *= i;
        }
        if (t > 1) {
            s.insert({i, t});
        }
    }
    if (y > 1) {
        s.insert({y, y});
    }
    i64 r = p;
    for (auto [i, t] : s) {
        i64 c = 1;
        while (x % i == 0) {
            x /= i;
            c *= i;
        }
        r = min(r, c / t * i);
    }
    i64 ans = p / r;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}