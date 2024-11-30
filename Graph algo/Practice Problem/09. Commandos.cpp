#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5, inf = 1e9;
vector<int> g[N];
bool vis[N];
int dist1[N];
queue<int> qu;
void bfs1(int st) {
    vis[st] = true;
    dist1[st] = 0;
    qu.push(st);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto v: g[u]) {
            if (!vis[v]) {
                dist1[v] = min(dist1[v], dist1[u] + 1);
                vis[v] = true;
                qu.push(v);
            }
        }
    }
}
int dist2[N];
bool vis2[N];
void bfs2(int st) {
    vis2[st] = true;
    dist2[st] = 0;
    qu.push(st);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto v: g[u]) {
            if (!vis2[v]) {
                dist2[v] = min(dist2[v], dist2[u] + 1);
                vis2[v] = true;
                qu.push(v);
            }
        }
    }
}
void solved() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        dist1[i] = dist2[i] = inf;
        vis[i] = vis2[i] = false;
        g[i].clear();
    }
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int st, en; cin >> st >> en;
    bfs1(st); bfs2(en);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int sum = dist1[i] + dist2[i];
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i <<": ";
        solved();
    }
    return 0;
}
