// Problem: B. Approximating a Constant Range
// Contest: Codeforces - Codeforces Round 333 (Div. 2)
// URL: https://codeforces.com/problemset/problem/602/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

// multiset
/* int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int l = 0;
    multiset<int> s;
    for (int r = 0; r < n; r++) {
        s.insert(a[r]);
        while (*s.rbegin() - *s.begin() > 1) {
            s.erase(s.find(a[l]));
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
} */

// map
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int l = 0;
    map<int, int> m;
    for (int r = 0; r < n; r++) {
        m[a[r]]++;
        while (m.size() > 2) {
            m[a[l]]--;
            if (m[a[l]] == 0) {
                m.erase(a[l]);
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}