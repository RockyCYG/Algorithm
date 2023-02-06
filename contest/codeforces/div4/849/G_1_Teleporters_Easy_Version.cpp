#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 a[200005];

void solve() {
    int n;
    i64 c;
    cin >> n >> c;
    i64 x;
    for (int i = 1; i <= n; i++) cin >> x, a[i] = i + x;
    sort(a + 1, a + n + 1);
    int i = 1;
    for (i = 1; i <= n && c >= a[i]; c -= a[i++]) {
    }
    cout << i - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}