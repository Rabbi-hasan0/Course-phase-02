#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
using namespace std;

const int N = 100;
vector<int> g[N];
int vis[N];
void dfs(int u) {
    vis[u] = true;
    for(auto &i: g[u]) {
        if(!vis[i]) {
            dfs(i);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        int n, e; cin >> e >> n;
        for(int i = 1; i <= e; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> store(n + 1, 0); 
        for(int i = 1; i <= n; i++) {      //// এই লুপে ১ নং কম্পনেন্ট এ কোন নোড গুলা আছে এইটা সেইভ করে রাখছি;
            if(!vis[i]) {
                dfs(i);
                store[i] = store[i - 1] + 1;
            } else {
                store[i] = store[i - 1];
            }
        } 
        int q = 1; cin >> q;        // তারপর query O(1) এ চেক দিচ্ছি যে x and y  একই কম্পনেন্ট এ কিনা! যদি সেইম কম্পনেন্ট এ থাকে তাহলে x to y যাবার পথ আছে;
        while(q--) {  
            int x, y; cin >> x >> y;
            if(store[x] == store[y]) {
                print("Yes");
            }
            else cout << "no" << "\n";
        }
    }
    return 0;
}
