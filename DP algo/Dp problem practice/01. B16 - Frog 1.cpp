#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5 + 5, inf = 1e9;
int dp[N], a[N], n;

// int rec(int i) {
//     if (i > n) return inf; 
//     if(i == n) return 0;
//     int &ans = dp[i];
//     if(ans != -1) return ans;  
//     ans = abs(a[i] - a[i + 1]) + rec(i + 1);
//     ans = min (ans, abs(a[i] - a[i + 2]) + rec(i + 2));
//     return ans; 
// } 
// int iterative() {
//     for(int i = n; i >= 1; i--) {
//       if(i == n) dp[i] = 0;
//       else {
//         int &ans = dp[i];
//         ans = abs(a[i] - a[i + 1]) + dp[i + 1];
//         if(i + 2 <= n) ans = min(ans, abs(a[i] - a[i + 2]) + dp[i + 2]);
//       }
//     }
//     return dp[1];
// }
int rec(int i) {
    if (i < 0) return inf; 
    if(i == 1) return 0;
    int &ans = dp[i];
    if(ans != -1) return ans;  
    ans = abs(a[i] - a[i - 1]) + rec(i - 1);
    ans = min(ans, abs(a[i] - a[i - 2]) +  rec(i - 2));
    return ans; 
} 
int iterative() {
    for(int i = 1; i <= n; i++) {
      if(i == 1) dp[i] = 0;
      else {
        int &ans = dp[i];
        ans = abs(a[i] - a[i - 1]) + dp[i - 1];
        if(i - 2 >= 1) ans = min(ans, abs(a[i] - a[i - 2]) + dp[i - 2]);
      }
    }
    return dp[n];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1; //cin >> t;
  while(t--){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // memset(dp, -1, sizeof dp);  
    // cout << rec(0) << '\n'; 
    // memset(dp, 0, sizeof dp);  
    // cout << iterative() << '\n';

    memset(dp, -1, sizeof dp);  
    cout << rec(n) << '\n'; 

    // memset(dp, 0, sizeof dp);  
    // cout << iterative() << '\n';
  }
  return 0;
}
