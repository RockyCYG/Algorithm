#include <bits/stdc++.h>

using namespace std;

// O(n^2)
class Solution1 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = 0x3f3f3f3f;
        int g[n][n];
        memset(g, 0x3f, sizeof(g));
        for (vector<int>& t : times) {
            g[t[0] - 1][t[1] - 1] = t[2];
        }
        int dis[n];
        memset(dis, 0x3f, sizeof(dis));
        dis[k - 1] = 0;
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            int cur = -1;
            for (int x = 0; x < n; x++) {
                if (!vis[x] && (cur == -1 || dis[x] < dis[cur])) {
                    cur = x;
                }
            }
            vis[cur] = true;
            for (int x = 0; x < n; x++) {
                dis[x] = min(dis[x], dis[cur] + g[cur][x]);
            }
        }
        int ans = *max_element(dis, dis + n);
        return ans == inf ? -1 : ans;
    }
};

// O(mlogn)
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = 0x3f3f3f3f;
        int g[n][n];
        memset(g, 0x3f, sizeof(g));
        for (vector<int>& t : times) {
            g[t[0] - 1][t[1] - 1] = t[2];
        }
        int dis[n];
        memset(dis, 0x3f, sizeof(dis));
        dis[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, k - 1});
        while (!q.empty()) {
            int d = q.top().first, cur = q.top().second;
            q.pop();
            if (dis[cur] < d) {
                continue;
            }
            for (int x = 0; x < n; x++) {
                if (dis[cur] + g[cur][x] < dis[x]) {
                    dis[x] = dis[cur] + g[cur][x];
                    q.push({dis[x], x});
                }
            }
        }
        int ans = *max_element(dis, dis + n);
        return ans == inf ? -1 : ans;
    }
};