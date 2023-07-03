// Problem: B. The Number of Products
// Contest: Codeforces - Codeforces Round 585 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1215/B
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
    int cnt[2] = {1, 0};
    int s = 0;
    int ans0 = 0, ans1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            s ^= 1;
        }
        ans0 += cnt[s ^ 1];
        ans1 += cnt[s];
        cnt[s]++;
    }
    cout << ans0 << ' ' << ans1 << '\n';
    return 0;
}