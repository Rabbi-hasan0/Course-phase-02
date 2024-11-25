<img src = "https://github.com/Rabbi-hasan0/Course-phase-01/blob/main/Graph%20algo/Graph-visual/2.png">

## 1. Applying [ Topology Sort ] Complexity: O(n&sup2;)

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> g[N];
bool vis[N];
int indegre[N];

int32_t main() {
    int T = 1; // cin >> T;
    while(T--) {
        int n, m;cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            indegre[v]++;
        }
        vector<int> ans;
        while(ans.size() < n) {
            int cur = 0;
            for(int i = 1; i <= n; i++) {     // Here to find which node have zero indegree as a condition of top sort 
                if(!indegre[i] and !vis[i]) {
                    cur = i; vis[i] = true;
                    break;
                }
            }
            if(cur == 0) {
                cout << ("Don't Possible") << '\n';
                break;
            }
            ans.push_back(cur);
            for(auto v: g[cur]) {   // (cur) node er sathe jei edge gula ache oy gula delete korlam, 
                indegre[v]--;       // mane jei node e gece oy node theke indegre komiye dilam tahole 
            }                       // delete hoye jabar moto kaj korlo...    
        }
        for(auto &i: ans) {
            cout << i << ' ';
        } cout << '\n';
    }
    return 0;
}
```
### Input:
```
6 6
6 3
6 1
5 1
5 2
3 4
4 2
```
### Output:
```
5 6 1 3 4 2
```
