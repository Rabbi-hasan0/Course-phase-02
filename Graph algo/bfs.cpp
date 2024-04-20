//bfs basic code just



#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector<int> graph[N];
bool vis[N];

int32_t main(){
    int node, edges;
    cin >> node >> edges;
    while(edges--) {
        int u, v;cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    q.push(1);vis[1] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto i: graph[u]) {
            if(!vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }

    return 0;
}
