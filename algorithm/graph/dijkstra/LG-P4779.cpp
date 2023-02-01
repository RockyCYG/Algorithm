#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100005, M = 400005;

struct edge {
    int to, dis, next;
};

int head[N], dis[N], tot;
edge edges[M];
int n, m, s;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

void add(int u, int v, int w) {
    edges[++tot].to = v;
    edges[tot].dis = w;
    edges[tot].next = head[u];
    head[u] = tot;
}

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int w = q.top().first, u = q.top().second;
        q.pop();
        if (dis[u] < w) {
            continue;
        }
        for (int i = head[u]; i; i = edges[i].next) {
            int v = edges[i].to, w = edges[i].dis;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << "\n";
    return 0;
}