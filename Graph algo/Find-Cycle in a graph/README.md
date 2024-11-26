<div style="display: flex; align-items: center;">
  <img src="https://raw.githubusercontent.com/Rabbi-hasan0/Course-phase-01/main/Graph%20algo/Graph-visual/3.png" alt="Image 1" width="300" height="300" style="margin-right: 40px;">
  <img src="https://raw.githubusercontent.com/Rabbi-hasan0/Course-phase-01/main/Graph%20algo/Graph-visual/2.png" alt="Image 2" width="300" height="300">
</div>

### Input:
```
3 3
1 2
2 3
3 1
```
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
