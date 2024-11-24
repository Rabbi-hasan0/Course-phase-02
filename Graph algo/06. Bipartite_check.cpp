// Reference CP algorithm page...

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, e;
vector<int> g[N];
vector<int> color;

bool is_bipartite() {
    bool ok = true;
    queue<int> q;
    for (int st = 1; st <= n; ++st) {
        if (color[st] == -1) {
            q.push(st);
            color[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : g[v]) {
                    if (color[u] == -1) {
                        color[u] = color[v] ^ 1;
                        q.push(u);
                    } else {
                        ok &= (color[u] != color[v]);
                    }
                }
            }
        }
    }
    return ok;
}
int32_t main() {
    cin >> n >> e;
    color.assign(n, -1);
    for (int i = 1; i <= e; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << (is_bipartite() ? "Bipartite" : "No Bipartite") << '\n';
    return 0;
}
