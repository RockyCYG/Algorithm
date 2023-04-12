// Problem: C. Yet Another Walking Robot
// Contest: Codeforces - Codeforces Round 617 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1296/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int, int>, int> hash;
    int x = 0, y = 0;
    int ans = 2e5 + 5;
    hash[{0, 0}] = -1;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'L') {
            x--;
        } else if (c == 'R') {
            x++;
        } else if (c == 'U') {
            y++;
        } else {
            y--;
        }
        if (hash.count({x, y})) {
            if (i - hash[{x, y}] - 1 < ans) {
                ans = i - hash[{x, y}] - 1;
                l = hash[{x, y}] + 1, r = i;
            }
        }
        hash[{x, y}] = i;
    }
    l++, r++;
    if (ans < 2e5 + 5) {
        cout << l << " " << r << "\n";
    } else {
        cout << -1 << "\n";
    }
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