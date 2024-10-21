#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 3005, inf = 1e9;
int dp[N][N];
int n, m; string a, b;

int lcs(int i, int j) {  //Recursive
    if(i == n or j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int ans = max(lcs(i + 1, j), lcs(i, j + 1));
    if(a[i] == b[j]) {
        ans = max(ans, lcs(i + 1, j + 1) + 1);
    }
    return dp[i][j] = ans;
}
void path(int i, int j) {
    if(i == n or j == m) return;
    if(a[i] == b[j]) {
        cout << a[i];
        path(i + 1, j + 1);
        return;
    } 
    int x = lcs(i + 1, j);
    int y = lcs(i, j + 1);
    if(x <= y) {
        path(i, j + 1);
    } else path(i + 1, j);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        cin >> a >> b;
        n = a.size(), m = b.size();
        memset(dp, -1, sizeof dp);
        path(0, 0);

    }
    return 0;
}
