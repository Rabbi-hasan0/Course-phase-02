#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;

vector<int> g[N];
vector<int> tk(N);
bool vis[N];
int ans, total;
void dfs(int n) {
  vis[n] = true;
  total += tk[n];
  ans++;
  for(auto &i: g[n]) {
    if(!vis[i]) {
        dfs(i);
    }
  }
}
void clearData() {
    for (int i = 0; i < N; ++i) {
        g[i].clear();
    }
    fill(tk.begin(), tk.end(), 0);
    fill(vis, vis + N, false);
    ans = total = 0;
}
void solved() {
    int n, m; cin >> n >> m;
    clearData();
    for(int i = 1; i <= n; ++i) {
        cin >> tk[i];
    }
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<int> dist;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ans = 0, total = 0;
            dfs(i);
            if(total % ans == 0) {
                dist.insert(total / ans);
            } else {
               print("No");
               return;
            }
        }
    }
    if(dist.size() == 1) {
        cout << "Yes\n";
    } else cout << "No\n";
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
