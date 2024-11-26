#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
void dfs(int u) {
    vis[u] = true;
    for(auto v: g[u]) {
        if(!vis[v]) dfs(v);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        while(m--) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u); 
        }
        vector<pair<int, int>> vp;
        int back = 0; dfs(1);
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                vp.push_back({back, i});
                dfs(i);
            }
            back = i;
        }
        cout << vp.size() << '\n';
        for(auto &[x, y]: vp) cout << x << ' ' << y << '\n';
    }
    return 0;
}
