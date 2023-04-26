// Problem: B. Greg and Graph
// Contest: Codeforces - Codeforces Round 179 (Div. 1)
// URL: https://codeforces.com/problemset/problem/295/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int f[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> f[i][j];
        }
    }
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    i64 ans[n];
    for (int q = n - 1; q >= 0; q--) {
        int k = a[q];
        vis[k] = true;
        ans[q] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                if (vis[i] && vis[j]) {
                    ans[q] += f[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}