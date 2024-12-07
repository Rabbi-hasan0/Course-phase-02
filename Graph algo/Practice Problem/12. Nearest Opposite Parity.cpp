#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int inf = 1e9;
const int N = 1e6 + 5;
vector<int> g[N]; 
int ans[N], dist[N];
int a[N], n;

void bfs(vector<int> &a, vector<int> &b) { 
    queue<int> qu;
    vector<int> dist(n + 1, inf);
    for(auto &st: a) {
        qu.push(st);
        dist[st] = 0;
    }
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto &v: g[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }
    for(auto &v: b) {
        ans[v] = dist[v];    // ith even number theke kon odd e jaoya jai oytai hocce oy odd er cost... Ejonno graph ultaye nichi, g[l] er moddhe I push dici..
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> even, odd;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] & 1) {
            odd.push_back(i);
        } else even.push_back(i);
    }
    for(int i = 1; i <= n; ++i) {
        int l = i - a[i], r = i + a[i];
        if (l > 0) {
            g[l].emplace_back(i);
        }
        if (r <= n) {
            g[r].emplace_back(i);
        }
    }
    bfs(even, odd);
    bfs(odd, even);
    for (int i = 1; i <= n; i++) {
        int x = (ans[i] == inf)? -1:ans[i];
        cout << x << ' '; 
    }
    cout << '\n';
    return 0;
}
