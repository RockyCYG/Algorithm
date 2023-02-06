#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 a[200005];

void solve() {
    int n;
    cin >> n;
    i64 sum = 0l;
    i64 minVal = 1e9;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            a[i] = -a[i];
            cnt++;
        }
        sum += a[i];
        minVal = min(minVal, a[i]);
    }
    i64 ans = sum;
    if (cnt % 2) ans -= 2 * minVal;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}