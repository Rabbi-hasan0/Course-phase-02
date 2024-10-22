#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9, mod = 1e9 + 7;
int dp[N][N], n, m; int a[N][N];
 
int rec(int i, int j) {
  if(i - 1 >= n or j - 1 >= m) return 0;
  if(i == n and j == m) return 1;
  if(a[i][j] == 0) return 0;
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = (rec(i, j + 1) + rec(i + 1, j)) % mod;
  return ans;
}
int iterative() {
    memset(dp, 0, sizeof dp);
    dp[1][1] = 1; 
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 0) continue;
            if(i > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if(j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }
    return dp[n][m];
}

int32_t main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            char ch; cin >> ch;
            a[i][j] = (ch == '.')?1:0;
        }
    }
    // memset(dp, -1, sizeof dp);
    // cout << rec(1, 1) << '\n';
    cout << iterative() << '\n';
    return 0;
}
