#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'U') {
            y++;
        } else if (c == 'D') {
            y--;
        } else if (c == 'L') {
            x--;
        } else {
            x++;
        }
        if (x == 1 && y == 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}