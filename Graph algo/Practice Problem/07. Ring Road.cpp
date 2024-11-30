#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;

vector<pair<int, int>> g[N];
bool vis[N];
int cost;

void dfs(int u, int p) {
  vis[u] = true;
  for(auto [v, charge]: g[u]) {
    if(!vis[v]) {
        cost += charge;
        dfs(v, u);
    } else {
        if(v == 1 and p != 1) {
            cost += charge;
        }
    }
  }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        int n, total_cost = 0; cin >> n;
        for(int i = 1; i <= n; i++) {
            int u, v, w; cin >> u >> v >> w;
            g[u].push_back({v, 0});
            g[v].push_back({u, w});
            total_cost += w;
        }
        cost = 0;  dfs(1, 0);
        int ans = min(cost, total_cost - cost);
        print(ans);
    }
    return 0;
}
