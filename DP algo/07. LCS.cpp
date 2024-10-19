// Find Long common subsequence string;
//  a = xyab
//  b = xaxycb
// --> How many lcs available? 


#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1005, inf = 1e9;
int dp[N][N];
int n, m; string a, b;

int lcs(int i, int j) {  //Recursive
    if(i == n or j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int ans = max(lcs(i + 1, j), lcs(i, j + 1));
    if(a[i] == b[j]) {
        ans = max(ans, lcs(i + 1, j + 1)) + 1;
    }
    return dp[i][j] = ans;
}

int it_lcs() {  //Iterative
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        } 
    }
    return dp[n][m];
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        cin >> a >> b;
        n = a.size(), m = b.size();
        memset(dp, -1, sizeof dp);
        cout << lcs(0, 0) << '\n';

        memset(dp, 0, sizeof dp);
        cout << iterative() << '\n'; //lcs() << '\n';

    }
    return 0;
}
