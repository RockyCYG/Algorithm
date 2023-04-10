// Problem: C. Maximum Median
// Contest: Codeforces - Codeforces Round 577 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1201/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

// 二分答案
/* int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int mid = a[n / 2];
    i64 l = mid - 1, r = a[n - 1] + k + 1;
    auto check = [&](i64 m) -> bool {
        i64 t = 0;
        for (int i = n / 2; i < n && a[i] < m; i++) {
            t += m - a[i];
        }
        return t <= k;
    };
    while (l + 1 < r) {
        i64 m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
    return 0;
} */

// 贪心
int main() {
    i64 n, k;
    cin >> n >> k;
    i64 a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int i = n / 2 + 1;
    for (; i < n; i++) {
        if (a[i] != a[i - 1]) {
            if (k < (i - n / 2) * (a[i] - a[i - 1])) {
                break;
            }
            k -= (i - n / 2) * (a[i] - a[i - 1]);
        }
    }
    i64 ans = a[i - 1] + k / (i - n / 2);
    cout << ans << endl;
    return 0;
}