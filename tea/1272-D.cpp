// Problem: D. Remove One Element
// Contest: Codeforces - Codeforces Round 605 (Div. 3)
// URL: https://codeforces.com/contest/1272/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

// dp状态机
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int f[n][2];
    memset(f, 0, sizeof(f));
    int ans = 1;
    for (int i = 0; i < n; i++) {
        f[i][0] = f[i][1] = 1;
        if (i > 0 && a[i] > a[i - 1]) {
            f[i][0] = max(f[i][0], f[i - 1][0] + 1);
            f[i][1] = max(f[i][1], f[i - 1][1] + 1);
        }
        if (i > 1 && a[i] > a[i - 2]) {
            f[i][1] = max(f[i][1], f[i - 2][0] + 1);
        }
        ans = max(ans, max(f[i][0], f[i][1]));
    }
    cout << ans << '\n';
    return 0;
}

// 前后缀分解
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int pre[n];
    memset(pre, 0, sizeof(pre));
    int ans = 1;
    pre[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            pre[i] = pre[i - 1] + 1;
            ans = max(ans, pre[i]);
        } else {
            pre[i] = 1;
        }
    }
    int suf = 1;
    for (int i = n - 2; i > 0; i--) {
        if (a[i + 1] > a[i - 1]) {
            ans = max(ans, pre[i - 1] + suf);
        }
        if (a[i] < a[i + 1]) {
            suf++;
        } else {
            suf = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}