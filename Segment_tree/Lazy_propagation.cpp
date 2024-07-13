
#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5 + 9;
int a[N + 1];
struct ST {
  #define lc (n << 1)          // define left child
  #define rc ((n << 1) + 1)    // define right child
  int t[4 * N], lazy[4 * N];
  static const int inf = 1e9; 
  ST() { // here just declear just all index are zero;
    memset(t, 0, sizeof(t));
    memset(lazy, 0, sizeof(lazy));
  }

  inline void pull(int n) {  // just a small function
    t[n] = t[lc] + t[rc];
  }
  inline int combine(int a,int b) {  // just a small function
    return a + b;
  }
  inline void push(int n, int b, int e) {  // Push means it adding a value with node which user want update 
    if(lazy[n] == 0) return;
    t[n] = t[n] + lazy[n] * (e - b + 1);   // Just t[n] node e declear kore dicci je hae ei node porjonto ok add kore dilam;
    if(b != e) {
      lazy[lc] = lazy[lc] + lazy[n];   // Just bole dilam je tmr and tmr nicher sob child_gula te lazy[n] add hobe;
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;   // lazy[n] add kore dici and tader child update kore dici thats why now no need to lazy[n], so lazy[n] declear as 0;
  }
  void build(int n, int b, int e) { // Ekhan theke n jacce macro lc and rc te😁😁😁
    lazy[n] = 0;    // Just normally simple segment tree er update and lazy[n] is declear as 0, na dileu pera hobe na maybe;
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }

  void update(int n, int b, int e, int i, int j, int val) { 
    push(n, b, e);   // here Just updating range value which is work push function and others same as simple segment tree code
    if(j < b || e < i) {
      return;
    }
    if(i <= b && e <= j) {
      lazy[n] = val;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    update(lc, b, mid, i, j, val);
    update(rc, mid + 1, e, i, j, val);
    pull(n); // here pull just a function which is just calculate operation like: addition, or, xor, and, max, min etc.
  }

  int query(int n, int b, int e, int i, int j) {
    push(n, b, e); 
    // here calling push cause ami sudhu jei node last visit koreci oy node e bole rakhcilam je tmr poregula te lazy[n] update hobe but update korcilam 
    // na just bole rakhcilam. Ekhn er nicher gulate jodi jete hoi then amk propagate kore niye jete hobe then update korte hobe tai call dici;
    if(j < b || e < i) {
      return 0;
    }
    if(i <= b && e <= j) {
      return t[n];
    }
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j)); // here combine just a function which is just calculate operation like: addition, or, xor, and, max, min etc.
  }
}st;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T--){
    int n = 5;
    for(int i = 1; i <= n; i++) {
      a[i] = i;
    }
    st.build(1, 1, n);
    // cout << st.query(1, 1, n, 1, 3) << '\n';
    // st.update(1, 1, n, 2, 3, 2);
    // cout << st.query(1, 1, n, 1, 3) << '\n';
    // cout << st.query(1, 1, n, 3, 5) << '\n';
    st.update(1, 1, n, 2, 3, 10); // adding 10 to the segment [2, 3]
    cout << st.query(1, 1, n, 1, 5) << '\n'; // range sum query on the segment [1, 5]  
  }
  return 0;
}
