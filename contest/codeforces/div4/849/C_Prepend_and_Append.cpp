#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int i = 0, j = n - 1;
    int ans = n;
    while (i < j) {
        if ((s[i] == '0' && s[j] == '1') || (s[i] == '1' && s[j] == '0')) {
            i++, j--;
            ans -= 2;
        } else {
            break;
        }
    }
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