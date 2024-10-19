#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int mod = 10000007;
int dp[10009], n, k;
int a, b, c, d, e, f;
int rec(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if (dp[n] != -1) return dp[n]; 
    dp[n] = (rec(n - 1) + rec(n - 2) + rec(n - 3) + rec(n - 4) + rec(n - 5) + rec(n - 6)) % mod;
    return dp[n];
}

void solved() {
    cin >> a >> b >> c >> d >> e >> f >> n;
    memset(dp, -1, sizeof dp);  
    cout << rec(n) % mod << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i <<": ";
        solved();
    }
    return 0;
}
