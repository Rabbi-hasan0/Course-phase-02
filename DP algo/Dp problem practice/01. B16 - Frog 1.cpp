#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5 + 5, inf = 1e9;
int dp[N], a[N], n;

int rec(int i) {
    if (i > n) return inf; 
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];  
    int ans = abs(a[i] - a[i + 1]) + rec(i + 1);
    ans = min (ans, abs(a[i] - a[i + 2]) + rec(i + 2));
    return dp[i] = ans; 
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
        memset(dp, -1, sizeof dp);  
        cout << rec(1) << '\n'; 
    }
    return 0;
}
