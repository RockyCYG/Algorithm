// Problem: B. Tree Tag
// Contest: Codeforces - Codeforces Round 668 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1404/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b, na, nb;
    cin >> n >> a >> b >> na >> nb;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (2 * na >= nb) {
        cout << "Alice\n";
        return;
    }
    int ab = 0, maxD = 0, p = 0;
    function<void(int, int, int)> dfs = [&](int x, int fa, int d) {
        if (x == b) {
            ab = d;
        }
        if (d > maxD) {
            maxD = d;
            p = x;
        }
        for (int y : g[x]) {
            if (y != fa) {
                dfs(y, x, d + 1);
            }
        }
    };
    dfs(a, 0, 0);
    if (na >= ab) {
        cout << "Alice\n";
        return;
    }
    maxD = 0;
    dfs(p, 0, 0);
    if (2 * na >= maxD) {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
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