#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5;
int dp[105][N], w[N], v[N]; 
int n, W;

// int knackshap(int i, int total_weight) {  /// When call recursive method then must pass(ind = 1 and weight = 0)
//   if(i - 1 == n) return 0;
//   if(dp[i][total_weight] != -1) return dp[i][total_weight];
//   int ans = knackshap(i + 1, total_weight); // Case 1: Do not take the item, just index pass kore dilam
//   if(total_weight + w[i] <= W) {
//     ans = max(ans, knackshap(i + 1, total_weight + w[i]) + v[i]); // // Case 2: Take the item (if it does not exceed capacity), sathe weight add korci + value add kore dici
//   }
//   return dp[i][total_weight] = ans;
// }

int knackshap() {
  for (int i = n; i > 0; --i) {
    for (int total_weight = 0; total_weight <= W; ++total_weight) {
        // Case 1: Do not take the item
        dp[i][total_weight] = dp[i + 1][total_weight]; 

        // Case 2: Take the item (if it does not exceed capacity)
        if (total_weight + w[i] <= W) {
            dp[i][total_weight] = max(dp[i][total_weight], dp[i + 1][total_weight + w[i]] + v[i]);
        }
    }
  }
  return dp[1][0];
}


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;//cin >> t;
  while(t--) {
    cin >> n >> W;
    for(int i = 1; i <= n; ++i) {
      cin >> w[i] >> v[i];
    } 
    memset(dp, 0, sizeof dp);
    cout << knackshap() << '\n';
  }
  return 0;
}
