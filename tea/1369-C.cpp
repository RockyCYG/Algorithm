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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> w(k);
    int one = 0;
    for (int i = 0; i < k; i++) {
        cin >> w[i];
        if (w[i] == 1) {
            one++;
        }
    }
    sort(a.begin(), a.end());
    sort(w.begin(), w.end());
    i64 ans = 0;
    for (int i = n - 1; i > n - 1 - one; i--) {
        ans += a[i] * 2;
    }
    sort(w.rbegin(), w.rend() - one);
    int j = 0;
    for (int i = n - 1 - one; i > n - 1 - k; i--) {
        ans += a[i] + a[j];
        j += w[n - 1 - i] - 1;
    }
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