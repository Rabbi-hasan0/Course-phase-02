#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9, mod = 1e9 + 7;
int dp[N], n;
 
int rec(int i) {
  if(i <= 0) return 0;
  if(i == 1) return 1;
  int &ans = dp[i];
  if(ans != 0) return ans;
  for(int j = 1; j <= min(i, 6); j++) {
    ans = (ans + rec(i - j)) % mod;
  }
  return ans;
}
int main() {
    cin >> n;
    memset(dp, 0, sizeof dp);
    int ans = rec(n + 1);
    cout << ans % mod << '\n';
 return 0;
}
