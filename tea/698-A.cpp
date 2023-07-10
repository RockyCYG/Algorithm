// Problem: A. Vacations
// Contest: Codeforces - Codeforces Round 363 (Div. 1)
// URL: https://codeforces.com/problemset/problem/698/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // int f[n + 1][3];
    // memset(f, 0, sizeof(f));
    // for (int i = 0; i < n; i++) {
    //     f[i + 1][0] = min(f[i][0], min(f[i][1], f[i][2])) + 1;
    //     if (a[i] == 1 || a[i] == 3) {
    //         f[i + 1][1] = min(f[i][0], f[i][2]);
    //     } else {
    //         f[i + 1][1] = INT_MAX;
    //     }
    //     if (a[i] == 2 || a[i] == 3) {
    //         f[i + 1][2] = min(f[i][0], f[i][1]);
    //     } else {
    //         f[i + 1][2] = INT_MAX;
    //     }
    // }
    // cout << min(f[n][0], min(f[n][1], f[n][2])) << '\n';
    vector<int> f(3);
    for (int i = 0; i < n; i++) {
        int x = f[0], y = f[1], z = f[2];
        f[0] = min(x, min(y, z)) + 1;
        if (a[i] == 1) {
            f[1] = min(x, z);
            f[2] = INT_MAX;
        } else if (a[i] == 2) {
            f[1] = INT_MAX;
            f[2] = min(x, y);
        } else if (a[i] == 3) {
            f[1] = min(x, z);
            f[2] = min(x, y);
        } else {
            f[1] = INT_MAX;
            f[2] = INT_MAX;
        }
    }
    cout << *min_element(f.begin(), f.end()) << '\n';
    return 0;
}