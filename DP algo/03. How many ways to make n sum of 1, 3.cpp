#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6;
int dp[N]; 

// int ways(int n) {  /// Using recursive method
//   if (n == 1) return 1;
//   if (n == 2) return 1;
//   if (n == 3) return 2;
//   if(dp[n] != -1) return dp[n];
//   return dp[n] = (ways(n - 1) + ways(n - 3)) % mod;
// }

int ways(int n) {  /// Using iterative method
  dp[1] = 1, dp[2] = 1, dp[3] = 2;
  for(int i = 4; i <= n; ++i) {
    dp[i] = (dp[i - 1] + dp[i - 3]) % mod;  
  }
  return dp[n];
}


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;//cin >> t;
  while(t--){
    memset(dp, -1, sizeof dp);
    dp[1] = 0;  
    cout << ways(55) << '\n';
  }
  return 0;
}
