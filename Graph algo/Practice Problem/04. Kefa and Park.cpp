#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e6 + 2;
vector<int> g[N], cat(N);
int n, m, ans, subseq[N];
bool vis[N];
void dfs(int u, int p) { 
    vis[u] = true;
    if(cat[u]) {
        subseq[u] = subseq[p] + 1;
    } else {
        subseq[u] = 0;
    }
    if(subseq[u] > m) return;
    bool is_leap = true;
    for(auto v: g[u]) {  
        if(!vis[v]) {     
            dfs(v, u);
            is_leap= false; 
        }
    }
    if(is_leap) ans++;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; // cin >> t;
    while(t--) {
        cin >> n >> m; 
        for(int i = 1; i <= n; i++) {
            cin >> cat[i];
        }
        for(int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 1);
        cout << ans << '\n';
    }
    return 0;
}
