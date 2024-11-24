#01. DFS-:
```cpp
    vector<int> g[N];
    bool vis[N];
    void dfs(int n) {
      vis[n] = true;
      for(auto &i: graph[n]) {
        if(!vis[i]) {
            dfs(i);
        }
      }
    }
```
#3. BFS-:
```cpp
    vector<int> g[N];
    bool vis[N];
    queue<int> qu;
    void bfs(int st) {
        vis[st] = true;
        qu.push(st);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for (int i : g[u]) {
                if (!vis[i]) {
                    vis[i] = true;
                    qu.push(i);
                }
            }
        }
    }
```
