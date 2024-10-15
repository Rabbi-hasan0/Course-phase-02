#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e6;
int dp[N]; 

// int min_steps(int n) {  /// Using recursive method
//   if(n == 1) return 0;
//   if(dp[n] != -1) return dp[n];
//   int ans = min_steps(n - 1) + 1;
//   if(n % 2 == 0) {
//     ans = min(ans, min_steps(n / 2) + 1);
//   }
//   if(n % 3 == 0) {
//     ans = min(ans, min_steps(n / 3) + 1);
//   }
//   return dp[n] = ans;
// }

int min_steps(int n) {  /// Using iterative method
  for(int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1] + 1;  
    if(i % 2 == 0) {
      dp[i] = min(dp[i], dp[i / 2] + 1); 
    }
    if(i % 3 == 0) {
      dp[i] = min(dp[i], dp[i / 3] + 1); 
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
    dp[1] = 0;  
    cout << min_steps(1000) << '\n';
  }
  return 0;
}
