// Problem: A. Hilbert's Hotel
// Contest: Codeforces - Codeforces Round 639 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1344/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool cnt[n];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        int x = ((a[i] + i) % n + n) % n;
        if (cnt[x]) {
            cout << "NO\n";
            return;
        }
        cnt[x] = true;
    }
    cout << "YES\n";
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