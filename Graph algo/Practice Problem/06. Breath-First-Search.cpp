#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
using namespace std;

const int N = 1e5;
vector<int> g[N];
bool vis[N];
int dist[N];
queue<int> qu;

void bfs(int st) {
    vis[st] = true;
    dist[st] = 0;
    qu.push(st);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto &v : g[u]) {
            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                qu.push(v);
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; // cin >> t;
    while (t--) {
        int n, total_cost = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int u, k;
            cin >> u >> k;
            while (k--) {
                int v;
                cin >> v;
                g[u].push_back(v);
            }
        }
        fill(dist + 1, dist + n + 1, n + 1);
        bfs(1);
        for (int i = 1; i <= n; i++) {
            cout << i << ' ' << (dist[i] == n + 1 ? -1 : dist[i]) << '\n';
        }
    }
    return 0;
}
