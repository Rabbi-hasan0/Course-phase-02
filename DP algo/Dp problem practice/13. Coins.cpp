#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 9, mod = 1e9 + 7;

double dp[N][N], a[N]; 
bool vis[N][N]; int n; 

double rec(int i, int head, int tail) {
    if(i == n + 1) {
        if(head > tail) return 1;
        else return 0;
    }
    if(vis[i][head]) return dp[i][head];
    vis[i][head] = true;
    double ans = a[i] * rec(i + 1, head + 1, tail);
    ans += (1 - a[i]) * rec(i + 1, head, tail + 1);
    return dp[i][head] = ans;
}

int32_t main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    //memset(dp, -1.0, sizeof dp);
    cout << fixed << setprecision(9) << rec(1, 0, 0) << '\n';
    return 0;
}
