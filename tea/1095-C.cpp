// Problem: C. Powers Of Two
// Contest: Codeforces - Codeforces Round 529 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1095/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    n -= k;
    vector<int> a(k, 1);
    for (int i = 0; i < k; i++) {
        for (; a[i] <= n; a[i] <<= 1) {
            n -= a[i];
        }
        if (n == 0) {
            cout << "YES\n";
            for (int x : a) {
                cout << x << " ";
            }
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}