/* 
Find shortest path using bfs and storing parent which from come?

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

*/

// Code:
<img src ="https://raw.githubusercontent.com/Rabbi-hasan0/Course-phase-01/refs/heads/main/Graph%20algo/Graph-visual/1.png"> 

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector<int> graph[N];
bool vis[N];
int dis[N], par[N];

int32_t main(){
    int node, edges;
    cin >> node >> edges;
    while(edges--) {
        int u, v;cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    q.push(1);vis[1] = true;dis[1] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto i: graph[u]) {
            if(!vis[i]) {
                q.push(i);
                par[i] = u;
                dis[i] = dis[u] + 1;
                vis[i] = true;
            }
        }
    }
    for(int i = 1; i <= node; i++) {
        cout << dis[i] << ' ';
    }cout << '\n';

    int v = 8;   // 1 to v porjonto shortest path khuje ber korbe
    while(v != 1) {
        cout << v << ' ';
        v = par[v];
    }
    cout << 1 << '\n';

    return 0;
}
