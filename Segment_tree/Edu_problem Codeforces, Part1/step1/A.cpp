#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e6 + 7;
int a[N + 5], t[4 * N];
void build(int node, int b, int e) {
    if(b == e) {
        t[node] = a[b];
        return;
    }
    int l = node * 2, r = l + 1;
    int mid = (b + e) >> 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = t[l] + t[r];
}
int query(int node, int b, int e, int l, int r) {
    if(l > e or r < b) return 0;
    if(b >= l and r >= e) {
        return t[node];
    }
    int mid = (b + e) >> 1;
    int left = node * 2, right = left + 1;
    return query(left, b, mid, l, r) + query(right, mid + 1, e, l, r);
}
void update(int node, int b, int e, int i, int v) {
    if(i < b or i > e) return;
    if(b == e and i == b) {
        t[node] = v;
        return;
    }
    int mid = (b + e) >> 1;
    int left = node * 2, right = left + 1;
    update(left, b, mid, i, v);
    update(right, mid + 1, e, i, v);
    t[node] = t[left] + t[right];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while(T--){
        int n, m;cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build(1, 0, n - 1);
        
        while(m--) {
            int p;cin >> p;
            if(p == 2) {
                int l ,r;cin >> l >> r;
                print(query(1, 0, n - 1, l, r - 1));
            }else {
                int i, v; cin >> i >> v;
                update(1, 0, n - 1, i, v);
            }
        }
    }
    return 0;
}
