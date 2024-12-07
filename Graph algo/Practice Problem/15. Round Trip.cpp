#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<int> g[N];
int color[N], parent[N];
int cycle_start, cycle_end;
bool cycle;

void dfs(int u, int p) {
    color[u] = 1;                       // Mark the node as visited (currently visiting)
    for (auto &v: g[u]) {
        if (v == p) continue;           // Skip the edge back to the parent
        if (color[v] == 0) {            // If the node is unvisited
            parent[v] = u;
            dfs(v, u);
            if (cycle) return;          // Stop further DFS if a cycle is found
        } else if (color[v] == 1) {     // Agei visit kora hoye gece...
            cycle = true;
            cycle_start = v;
            cycle_end = u;
            return;
        }
    }
    color[u] = 2;                       // Mark the node as fully processed
}

void print_path() {
    int v = cycle_end;
    stack <int> path;
    path.push(cycle_start);
    while (v != cycle_start) {
        path.push(v);
        v = parent[v];
    }
    path.push(cycle_start);
    cout << path.size() << '\n';
    while(!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u); 
        }
        cycle = false;
        cycle_start = -1;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) dfs(i, 0); 
            if (cycle) break;
        }
        if (cycle) {
            print_path();
        } else {
            print("IMPOSSIBLE");
        }
    }
    return 0;
}
