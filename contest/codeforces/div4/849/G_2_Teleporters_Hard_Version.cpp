#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    i64 c;
    cin >> n >> c;
    vector<pair<i64, i64>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        i64 x;
        cin >> x;
        a[i] = {x + min(i, n + 1 - i), i + x};
    }
    sort(a.begin() + 1, a.end());
    vector<i64> presum(n + 1);
    for (int i = 1; i <= n; i++) {
        presum[i] = presum[i - 1] + a[i].first;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].second > c) {
            continue;
        }
        int lo = 0, hi = n + 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            i64 val = presum[mid];
            if (mid >= i) {
                val -= a[i].first;
            }
            if (val + a[i].second <= c) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        ans = max(ans, lo + 1 - (lo >= i));
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}