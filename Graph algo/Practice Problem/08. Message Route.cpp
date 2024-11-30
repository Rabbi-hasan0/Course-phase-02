#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
using namespace std;

const int N = 1e6, inf = 1e9;
vector<int> g[N];
bool vis[N];
int dist[N], parent[N];
queue<int> qu;
void bfs(int st) {
    vis[st] = true;
    dist[st] = 0;
    qu.push(st);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto &v: g[u]) {
            if (!vis[v]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                }
                vis[v] = true;
                qu.push(v);
            }
        }
    }
}

void print_path(int n) {
    vector<int> path;
    int u = parent[n];
    path.push_back(n);
    while(u != 1) {
        path.push_back(u);
        u = parent[u];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for(auto &i: path) {
        cout << i << ' ';
    } cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 1; i <= n; ++i) {
            dist[i] = inf;
        }
        bfs(1);
        if(dist[n] == inf) {
            print("IMPOSSIBLE");
        } else {
            print(dist[n] + 1);
            print_path(n);
        }
    }
    return 0;
}
