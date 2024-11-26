<img src = "https://raw.githubusercontent.com/Rabbi-hasan0/Course-phase-01/refs/heads/main/Graph%20algo/Graph-visual/1.png">

### Input:
```
8 8
1 2 
1 4 
1 3
2 5
2 6
3 6
4 7
7 8
```
### 1. Find sortest path [ by bfs ] Complexity: O( v + e)
```c++
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> g[N];
bool vis[N];
int dis[N], parent[N];
queue<int> q;

void bfs(int st) {
    q.push(st);
    vis[st] = true;
    dis[1] = 0;           // define layer 0; 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto i: g[u]) {
            if(!vis[i]) {
                q.push(i);
                parent[i] = u;    // এই নোডের parent কোনটা ওইটা সেভ করে রাখছি, লুপের নোডগুলার parent তোহ u তাই সব নোডে u save করে রাখলাম।
                dis[i] = dis[u] + 1;      // new layer e jacci eikhan theke so (ager layer er sathe 1 add kore dicci);
                vis[i] = true;
            }
        }
    }
}

void print_path(int v) {
    while(v != 1) {
        cout << v << ' ';
        v = parent[v];
    }
    cout << 1 << '\n';
}

int32_t main(){
    int n, e;
    cin >> n >> e;
    while(e--) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    for(int i = 1; i <= n; i++) { // Kon layer e koto gula node ache eta dekha jai
        cout << dis[i] << ' ';
    }cout << '\n';
    cout << dis[8] << '\n'; // Print 8 koto number layer e ache..!
    print_path(6); // 6 theke 1 e jabar path print koro, jehetu bfs chalacci tai eitai shortest path

    return 0;
}
```
### Output:
```
8 7 4 1
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
