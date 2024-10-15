#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6;
int dp[N]; 

// int ways(int n) {  /// Using recursive method
//   if(n == 0) return 1;
//   if(dp[n] != -1) return dp[n];
//   int ans = 0;
//   for(int i = 1; i <= n; i++) {
//     ans += ways(n - i) % mod;
//   }
//   return dp[n] = ans;
// }

int ways(int n) {  /// Using iterative method
  dp[0] = 1;
  for(int i = 1; i <= n; ++i) {
    dp[i] = 0;
    for(int j = 1; j <= i; j++) {
        dp[i] += dp[i - j] % mod;
    }  
  }
  return dp[n];
}


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;//cin >> t;
  while(t--){
    memset(dp, -1, sizeof dp);
    cout << ways(10000) << '\n';
  }
  return 0;
}
