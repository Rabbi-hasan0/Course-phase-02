<div>
<h2 align="left"> 1. Find Cycle On Directed Graph </h2> 
<div align="center">
  <img src="https://github.com/Rabbi-hasan0/Course-phase-01/blob/main/Graph%20algo/Graph-visual/3.png" width="560" height="315">
</div>



### Input:
```
3 3
1 2
2 3
3 1
```

<h3 align="center"> Applying [dfs] for finding cycle;  Complexity: O(v + e) </h3> 

```c++
#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<int> g[N];
int color[N]; 
bool cycle; 

void dfs(int u) {
    color[u] = 1; // 1 means node are red, means this node is in the dfs and current not end dfs, if any edges connect this node then must cycle..
    for(auto v: g[u]) {
        if(color[v] == 0) { // 0 means current not visited node
            dfs(v);
        }
        else {
            if(color[v] == 1) {
                cycle = true;
            }
        }
    }
    // After this loop means end dfs of this node, then this node mark as visited
    color[u] = 2; // 2 kore debar por kono edge gele loop create hobe na but 2 kore rakhci karon eita visited eita ar visit korte hobe na
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
        }
        cycle = false;
        for(int i = 1; i <= n; i++) {
            if(color[i] == 0) dfs(i);
        }
        
        print((cycle?"Yes":"No"));
    }
    return 0;
}
```
### Output:
```
Yes
```

## If want to print path of Cycle:
```c++
#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<int> g[N];
int color[N], parent[N];
bool cycle;
int cycle_start, cycle_end;

void dfs(int u) {
    color[u] = 1;
    for (auto v : g[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            dfs(v);
        } else if (color[v] == 1) {
            cycle = true;
            cycle_start = v;
            cycle_end = u;
            return;
        }
    }
    color[u] = 2;
}
void print_path() {
    vector<int> path;
    int v = cycle_end;
    path.push_back(cycle_start);
    while(v != cycle_start) {
         path.push_back(v);
         v = parent[v];
    }
    path.push_back(cycle_start);
    reverse(path.begin(), path.end());
    for(auto v: path) {
        cout << v << ' ';
    } cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        cycle = false;
        cycle_start = -1;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) dfs(i);
            if (cycle) break;
        }
        if (cycle) {
            print("Yes");
            print_path();
        } else {
            print("No");
        }
    }
    return 0;
}
```
</div>

<div>
  <h2 align="center"> Find Cycle On Un-Directed Graph </h2>
</div>
