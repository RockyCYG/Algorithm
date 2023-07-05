// Problem: C2. Increasing Subsequence (hard version)
// Contest: Codeforces - Codeforces Round 555 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1157/C2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    int l = 0, r = n - 1;
    string ans;
    int cnt = 0;
    int pre = 0;
    while (l <= r) {
        if (max(a[l], a[r]) <= pre) {
            break;
        }
        if (a[l] > a[r]) {
            if (a[r] > pre) {
                pre = a[r];
                r--;
                ans += 'R';
            } else {
                pre = a[l];
                l++;
                ans += 'L';
            }
        } else if (a[l] < a[r]) {
            if (a[l] > pre) {
                pre = a[l];
                l++;
                ans += 'L';
            } else {
                pre = a[r];
                r--;
                ans += 'R';
            }
        } else {
            int nl = l, nr = r;
            nl++;
            while (nl <= nr && a[nl] > a[nl - 1]) {
                nl++;
            }
            int c1 = nl - l;
            nl = l;
            nr--;
            while (nl <= nr && a[nr] > a[nr + 1]) {
                nr--;
            }
            int c2 = r - nr;
            if (c1 >= c2) {
                pre = a[l];
                l++;
                ans += 'L';
            } else {
                pre = a[r];
                r--;
                ans += 'R';
            }
        }
        cnt++;
    }
    cout << cnt << '\n'
         << ans << '\n';
    return 0;
}