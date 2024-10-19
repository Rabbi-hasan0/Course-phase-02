#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5 + 5, inf = 1e9;
int dp[N], a[N], n, k;

// int rec(int i) {
//     if (i > n) return 0; 
//     if(i == n) return 0;
//     int &ans = dp[i];
//     if(ans != -1) return ans; 
//     ans = inf;
//     for(int j = i + 1; j <= i + k; j++) {
//         if(j <= n) {
//             ans = min(ans, abs(a[i] - a[j]) + rec(j));
//         }
//     } 
//     return ans; 
// } 

// int iterative() {
//     for(int i = n; i > 0; --i) {
//         if(i == n) {dp[i] = 0; continue;}
//         int ans = inf;
//         for(int j = i + 1; j <= i + k and j <= n; ++j) {
//             ans = min(ans, abs(a[i] - a[j]) + dp[j]);
//         }
//         dp[i] = ans;
//     }
//     return dp[1];
// }

int iterative() {
    for(int i = 1; i <= n; ++i) {
        if(i == 1) {dp[i] = 0; continue;}
        int ans = inf;
        for(int j = i - 1; j >= i - k and j >= 1; --j) {
            ans = min(ans, abs(a[i] - a[j]) + dp[j]);
            //cout << ans << ' ';
        } //cout << '\n';
        dp[i] = ans;
    }
    return dp[n];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        // memset(dp, -1, sizeof dp);  
        // cout << rec(1) << '\n'; 
        memset(dp, 0, sizeof dp);  
        cout << iterative() << '\n'; 
    }
    return 0;
}
