#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    unordered_map<char, int> hash;
    unordered_set<char> pre;
    for (char c : s) hash[c] += 1;
    int maxVal = 0;
    for (int i = 0; i < n - 1; i++) {
        char c = s[i];
        pre.insert(c);
        hash[c] -= 1;
        if (hash[c] == 0) hash.erase(c);
        maxVal = max(maxVal, int(hash.size() + pre.size()));
    }
    cout << maxVal << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}