#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;cin >> t;
    int a[t + 1][t + 1];
    for(int i = 1; i <= t; ++i) {
        for(int j = 1; j <= t; ++j) {
            a[i][j] = 0;
        }
    }
    for(int i = 1; i <= t; i++){
        int u, k; cin >> u >> k;
        while(k--) {
            int x; cin >> x;
            a[u][x] = 1;
        }
    }
    for(int i = 1; i <= t; ++i) {
        for(int j = 1; j <= t; ++j) {
            cout << a[i][j] << ' ';
        } cout << '\n';
    } cout << '\n';
    
    return 0;
}
