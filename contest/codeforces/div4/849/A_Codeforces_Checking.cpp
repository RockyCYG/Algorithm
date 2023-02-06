#include <bits/stdc++.h>

using namespace std;

void solve() {
    char c;
    cin >> c;
    unordered_set<char> hash;
    string s = "codeforces";
    for (char ch : s) hash.insert(ch);
    if (hash.find(c) != hash.end()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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