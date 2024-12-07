#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1010;
string s[N];
int vis[N][N];
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool is_valid(int i, int j) {
    return (i < n and j < m and i > -1 and j > -1);
}
void dfs(int i, int j) {
    vis[i][j] = true;
    for(int k = 0; k < 4; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(is_valid(nx, ny) and !vis[nx][ny] and s[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '.' and !vis[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        print(ans);
    }
    return 0;
}
