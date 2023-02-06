#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
    int n, q;
    cin >> n >> q;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 10) {
            s.insert(i);
        }
    }
    while (q--) {
        int i;
        cin >> i;
        if (i == 1) {
            int l, r;
            cin >> l >> r;
            auto it = s.lower_bound(l);
            while (it != s.end() && *it <= r) {
                int idx = *it;
                int t = a[idx];
                a[idx] = 0;
                while (t > 0) {
                    a[idx] += t % 10;
                    t /= 10;
                }
                if (a[idx] < 10) {
                    it = s.erase(it);
                } else {
                    it++;
                }
            }
        } else {
            int x;
            cin >> x;
            cout << a[x] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}