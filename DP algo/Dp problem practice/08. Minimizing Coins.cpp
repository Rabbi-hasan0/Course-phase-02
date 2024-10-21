#include<bits/stdc++.h>
#define int long long
#define print(x) cout << x << '\n'
using namespace std;

const int N = 2e6 + 7;
const int NN = 109;
int a[N], n, dp[N], m;

int rec(int i) {
    if(i == 0) return 0;
    if(dp[i] != -1 ) return dp[i];
    int ans = 1e9;
    for(int j = 1; j <= n; j++) {
        if(i < a[j]) break;
        int x = i - a[j];
        ans = min(ans, rec(x) + 1);
    }
    return dp[i] = ans;
}

int iterative() {
  fill(dp, dp + N, 1e9);
  dp[0] = 0;
  for(int i = 1; i <= m; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(i - a[j] < 0) break;
      int need = i - a[j];
      dp[i] = min(dp[i], dp[need] + 1);
    }
  }
  if(dp[m] < 1e9) return dp[m];
  else return -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) {
        cin >> n >> m;  
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        fill(dp, dp + N, -1);
        int ans = rec(m);
        cout << (ans < 1e9? ans: -1)  << '\n';

        //cout << iterative() << '\n';
    }
    return 0;
}
