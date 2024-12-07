#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 110;
string s[N];
int vis[N][N];
int n, m;
int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
bool is_valid(int i, int j) {
    return (i < n and j < m and i > -1 and j > -1);
}
void dfs(int i, int j) {
    vis[i][j] = true;
    for(int k = 0; k < 8; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(is_valid(nx, ny) and !vis[nx][ny] and s[nx][ny] == '@') {
            dfs(nx, ny);
        }
    }
}
// ---> Or,
// void dfs(int i, int j) {
//     vis[i][j] = true;
//     if (i - 1 >= 0 and s[i - 1][j] == '@' and !vis[i - 1][j]) dfs(i - 1, j);       // Up
//     if (i + 1 < n and s[i + 1][j] == '@' and !vis[i + 1][j]) dfs(i + 1, j);       // Down
//     if (j - 1 >= 0 and s[i][j - 1] == '@' and !vis[i][j - 1]) dfs(i, j - 1);      // Left
//     if (j + 1 < m and s[i][j + 1] == '@' and !vis[i][j + 1]) dfs(i, j + 1);      // Right

//     if (i - 1 >= 0 and j - 1 >= 0 and s[i - 1][j - 1] == '@' and !vis[i - 1][j - 1]) dfs(i - 1, j - 1); // Top-left
//     if (i - 1 >= 0 and j + 1 < m and s[i - 1][j + 1] == '@' and !vis[i - 1][j + 1]) dfs(i - 1, j + 1); // Top-right
//     if (i + 1 < n and j + 1 < m and s[i + 1][j + 1] == '@' and !vis[i + 1][j + 1]) dfs(i + 1, j + 1); // Bottom-right
//     if (i + 1 < n and j - 1 >= 0 and s[i + 1][j - 1] == '@' and !vis[i + 1][j - 1]) dfs(i + 1, j - 1); // Bottom-left
// }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m and n and m) {
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '@' and !vis[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        print(ans);
    }
    return 0;
}
