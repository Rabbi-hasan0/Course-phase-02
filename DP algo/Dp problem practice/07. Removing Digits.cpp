#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e6 + 9;
int dp[N], n;

int mx_digit(int n) {
    int mx = 0;
    while(n) {
        int x = n % 10;
        mx = max(mx, x);
        n /= 10;
    }
    return mx;
}

int rec(int n) {
    if(n <= 10) return 2;
    int &ans = dp[n];
    if(ans != -1) return ans;
    int temp = n;
    vector<int> d;
    while (temp) {
        d.push_back(temp % 10);
        temp /= 10;
    }
    ans = 1e9;
    for (auto &i: d) {
        if (i == 0) continue;
        ans = min(ans, 1 + rec(n - i));
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) {
        int n; cin >> n;
        int cnt = 0;
        while(n) {
            n -= mx_digit(n);
            cnt++;
            // cout << n << ' ';
        }
        cout << cnt << '\n';
        // memset(dp, -1, sizeof dp);
        // cout << rec(n) - 1 << '\n';
    }
    return 0;
}
