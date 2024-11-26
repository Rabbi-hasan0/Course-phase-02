#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 110;
vector<int> g[N];
bool vis[N];
int start[N], finish[N], cur;
void dfs(int u) {
    vis[u] = true;
    start[u] = ++cur;
    for(auto v: g[u]) {
        if(!vis[v]) dfs(v);
    }
    finish[u] = ++cur;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;cin >> t;
    for(int i = 1; i <= t; i++){
        int u, k; cin >> u >> k;
        while(k--) {
            int v; cin >> v;
            g[u].push_back(v);
        }
        // cout << u << ':';
        // for(auto v: g[u]) cout << v << ' '; cout << '\n';
        sort(g[u].begin(), g[u].end());
    }
    cur = 0;
    for(int i = 1; i <= t; ++i) {
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= t; ++i) {
        cout << i << ' ' << start[i] << ' ' << finish[i] << '\n';
    }
    
    return 0;
}
