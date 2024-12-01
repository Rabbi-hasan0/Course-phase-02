#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5;
vector<int> g[N];
map<int, int> mp;
bool vis[N];
void dfs(int n) {
  vis[n] = true;
  mp[n]++;
  for(auto &i: g[n]) {
    if(!vis[i]) {
        dfs(i);
    }
  }
}
void solved() {
    int k, n, m; cin >> k >> n >> m;
    for(int i = 1; i <= n; ++i) {
        mp[i] = 0;
        g[i].clear();
    }
    vector<int> person(k + 1);
    for(int i = 1; i <= k; ++i) {
        cin >> person[i];
    }
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    
    for(int i = 1; i <= k; ++i) {
        fill(vis, vis + n + 1, false);
        dfs(person[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(mp[i] == k) ans++;
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
