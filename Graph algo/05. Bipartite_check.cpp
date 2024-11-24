
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> g[N];
bool vis[N], ok;
int color[N];
int n, e;
void dfs(int u) {
    vis[u] = true;
    for(auto &v: g[u]) {
        if(!vis[v]) {
            color[v] = color[u] ^ 1;         // parent node 0 hole child node 1 and parent node 1 hole child node 0 kore dilam...
            dfs(v);
        } else {
            if(color[u] == color[v]) {       // jodi parent node and child node mile jai tahole false hoye jabe..
                ok = false;
            }
        }
    }
}
int32_t main(){
    cin >> n >> e;
    while(e--) {
        int u, v;cin >> u >> v; 
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ok = true;
    for(int i = 1; i <= n; ++i) {       // Disconnected graph hole ..
        if(!vis[i]) dfs(i);
    }
    cout << (ok?"Bipartite":"No Bipartite") << '\n';
    return 0;
}
