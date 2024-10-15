#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e6;
int dp[N]; 
bool vis[N];

// int fibo(int n) {                                   /// Using Recusion method
//   if(n == 0) return 0;
//   if(n == 1) return 1;
//   if(vis[n]) return dp[n];
//   dp[n] = fibo(n - 1) + fibo(n - 2);
//   vis[n] = true;
//   return dp[n];
// }

int fibo(int n) {                                    /// Using iterative method
  for(int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;//cin >> t;
  while(t--){
    //memset(dp, -1, sizeof dp);
    dp[0] = 0, dp[1] = 1;
    cout << fibo(1000) << '\n';
  }
  return 0;
}
