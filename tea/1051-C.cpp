// Problem: C. Vasya and Multisets
// Contest: Codeforces - Educational Codeforces Round 51 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1051/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        cnt[s[i]]++;
    }
    unordered_set<int> s1, s2;
    for (auto [k, v] : cnt) {
        if (v == 1) {
            s1.insert(k);
        } else if (v > 2) {
            s2.insert(k);
        }
    }
    int x = s1.size(), y = s2.size();
    string ans(n, 'A');
    if (x % 2 == 0) {
        cout << "YES\n";
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[s[i]] == 1) {
                ans[i] = 'B';
                if (++c == x / 2) {
                    break;
                }
            }
        }
        cout << ans << '\n';
    } else {
        if (y > 0) {
            cout << "YES\n";
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (c >= x / 2) {
                    break;
                }
                if (cnt[s[i]] == 1) {
                    ans[i] = 'B';
                    c++;
                }
            }
            int z = *(s2.begin());
            for (int i = 0; i < n; i++) {
                if (s[i] == z) {
                    ans[i] = 'B';
                    break;
                }
            }
            cout << ans << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}