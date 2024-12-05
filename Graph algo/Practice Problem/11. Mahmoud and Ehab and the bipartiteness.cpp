#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e6;
vector<int> g[N];
bool vis[N];
int edge_cnt[N];
int color[N];
queue<int> qu;
void bfs(int st) {
    vis[st] = true;
    qu.push(st);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto v: g[u]) {
            if (!vis[v]) {
                edge_cnt[u]++;
                edge_cnt[v]++;
                color[v] = color[u] ^ 1;
                vis[v] = true;
                qu.push(v);
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bfs(1);
        int cnt[2] = {0, 0};
        for(int i = 1; i <= n; ++i) {
            ++cnt[color[i]];
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(color[i] == 1) {
                ans += cnt[0] - edge_cnt[i];
            } else ans += cnt[1] - edge_cnt[i];
        }
        print(ans / 2);
    }
    return 0;
}
