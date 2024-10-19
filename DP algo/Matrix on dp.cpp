[1, 7, 9, 2]
[8, 6, 3, 2]
[1, 6, 7, 8]
[2, 9, 2, 2]
--> We want to going [1][1] index to [n][m] index with minimum path cost...




#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1005, inf = 1e9;
int dp[N][N], a[N][N];
int n, m;

int rec(int i, int j) {
    if(i > n or j > m) return inf;
    if(i == n and j == m) return a[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = min(rec(i + 1, j), rec(i, j + 1)) + a[i][j];

    return dp[i][j];
}

int iterative() {
    dp[1][1] = a[1][1];
    for(int i = 2; i <= n; i++) {
        dp[1][i] = dp[1][i - 1] + a[1][i];
    }
    for(int i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] + a[i][1];
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= m; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        } 
    }

    return dp[n][m];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cin >> a[i][j];
            }
        } 
        memset(dp, -1, sizeof dp);
        cout << rec(1, 1) << '\n';

        memset(dp, -1, sizeof dp);
        cout << iterative() << '\n';

    }
    return 0;
}
