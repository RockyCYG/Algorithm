// Problem: D. Program
// Contest: Codeforces - Educational Codeforces Round 102 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1473/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

struct Pre {
	int cur{};
	int max{};
	int min{};
};

struct Suf {
	int up{};
	int down{};
};

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<Pre> pre(n + 1);
	vector<Suf> suf(n + 1);
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+') {
			x++;
		} else {
			x--;
		}
		pre[i + 1].cur = x;
		pre[i + 1].max = max(pre[i].max, x);
		pre[i + 1].min = min(pre[i].min, x);
	}
	int mx = 0, mn = 0;
	x = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '+') {
			x--;
		} else {
			x++;
		}
		mx = max(mx, x);
		mn = min(mn, x);
		suf[i].up = mx - x;
		suf[i].down = mn - x;
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		int up = max(pre[l - 1].max, pre[l - 1].cur + suf[r].up);
		int down = min(pre[l - 1].min, pre[l - 1].cur + suf[r].down);
		int ans = up - down + 1;
		cout << ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}