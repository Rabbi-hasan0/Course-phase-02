#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
using namespace std;

const int N = 110;
int g[N][N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;cin >> t;
    int n = t;
    while(t--){
        int u, k;cin >> u >> k;
        while(k--) {
          int v;cin >> v;
          g[u][v] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        cout << g[i][j] << ' ';
      }cout << '\n';
    }cout << '\n';
    return 0;
}
