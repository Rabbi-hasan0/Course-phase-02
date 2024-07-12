#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define ll long long
using namespace std;
const int N = 1e5;
int a[N], t[4 * N];

void build(int node, int b, int e) {
    if(b == e) {
        t[node] = a[b];
        return;
    }
    int l = node * 2, r = l + 1;
    int mid = (b + e) >> 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = max(t[l] , t[r]);
}

int query(int node, int b, int e, int i, int j) { // here l, r is given as query 
    //check condition if node is totally outside;
    if(b > j or e < i) {
        return 0;
    }
    //check condition if node is totally inside;
    if(i <= b and e <= j) {
        return t[node];
    }

    int l = node * 2, r = l + 1;
    int mid = (b + e) >> 1;
    return max(query(l, b, mid, i, j) ,query(r, mid + 1, e, i, j));
}

void update(int node, int b, int e, int i, int val) {
    // If i is out of range then return;
    if(i < b or e < i) {
        return;
    }
    // If satisfy my condition then update;
    if(b == e and i == b) {
        t[node] = val;
        return;
    } 

    int mid = (b + e) >> 1;
    int l = node * 2, r = l + 1;
    update(l, b, mid, i, val);
    update(r, mid + 1, e, i, val);
    t[node] = max(t[l] , t[r]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;//cin >> t;
    while(T--){
        int n = 5;
        for(int i = 1; i <= n; i++) {
            a[i] = i;
        }
        build(1, 1, n);
        cout << query(1, 1, n, 2, 4) << '\n';
        update(1, 1, n, 3, 6);
        cout << query(1, 1, n, 2, 4) << '\n';
    }
    return 0;
}
