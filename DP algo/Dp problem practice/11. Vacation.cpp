#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e6, inf = 1e9;
int dp[N][4], a[N][4];
int n;

int rec(int i, int j) {
    if (i <= 0 || j <= 0 || j > 3) {
        return 0;
    }
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    
    if (j == 1) {
        ans = max(rec(i - 1, j + 1), rec(i - 1, j + 2)) + a[i][j];
    }
    else if (j == 2) {
        ans = max(rec(i - 1, j - 1), rec(i - 1, j + 1)) + a[i][j];
    }
    else if (j == 3) {
        ans = max(rec(i - 1, j - 1), rec(i - 1, j - 2)) + a[i][j];
    }
    return ans;
}

int iterative() {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == 1) {
                dp[i][j] = max(dp[i - 1][j + 1], dp[i - 1][j + 2]) + a[i][j];
            }
            if (j == 2) {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j + 1]) + a[i][j];
            }
            if (j == 3) {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j - 2]) + a[i][j];
            }
        }
    }
  
    int ans = 0;
    for (int j = 1; j <= 3; j++) {
        ans = max(ans, dp[n][j]);
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j];
            }
        }
        
        //cout << iterative() << '\n';
        
        memset(dp, -1, sizeof dp);
        int res = 0;
        for (int j = 1; j <= 3; j++) {
            res = max(res, rec(n, j));
        }
        cout << res << '\n';
    }
    return 0;
}
