problem:
Find sortest path 1 to 8;
Input: 
8 8
1 2 
1 4 
1 3
2 5
2 6
3 6
4 7
7 8
output:
8 7 4 1
->> visualization of graph:    [https://raw.githubusercontent.com/Rabbi-hasan0/Course-phase-01/refs/heads/main/Graph%20algo/Graph-visual/1.png]



// Code: 

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
