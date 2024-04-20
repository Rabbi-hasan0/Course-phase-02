/*
Input:
7 7
1 2 
1 4 
1 3
2 5
2 6
3 6
4 7
Output:
  Connected..


Graph: 
       (1)
     /  |  \
  (2)   |   (3)
  / \  (4)     \
 /   \          \
(5)  (6)        (7)


*/

code:

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector<int> graph[N];
bool vis[N];
void dfs(int n) {
  vis[n] = true;
  for(auto &i: graph[n]) {
    if(!vis[i]) {
        dfs(i);
    }
  }
}

int32_t main(){
    int node, edges;
    cin >> node >> edges;
    while(edges--) {
        int u, v;cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i <= node; i++) {
        if(!vis[i]) {
            cout << "Disconnected graph\n";
            return 0;
        }
    }
    cout << "Connected\n";

    return 0;
}
