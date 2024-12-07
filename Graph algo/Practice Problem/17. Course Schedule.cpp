#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e6;
vector<int> g[N];

void printt(vector<int> &path) {
    for(auto &i: path) {
        cout << i << ' ';
    } cout << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; // cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> indeg(n + 1, 0);
        for (int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            indeg[v]++;
        }
        queue<int> qu;
        for(int i = 1; i <= n; ++i) {
            if(indeg[i] == 0) {
                qu.push(i);
            }
        }

        vector<int> path;
        while (!qu.empty()) {
            int u = qu.front();
            path.push_back(u);
            qu.pop();
            for (auto v: g[u]) {
                indeg[v]--;
                if(indeg[v] == 0) qu.push(v);
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(indeg[i] > 0) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        printt(path);
    }
    return 0;
}
