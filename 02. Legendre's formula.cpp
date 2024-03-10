

#include<bits/stdc++.h>
using namespace std;

int legendre(long long n, long long p) {
  int ans = 0;
  while (n) {
    ans += n / p;      // This work = (n/p^1 + n/(p^2) + ... + n/(p^n)
    n /= p;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  cout << "The largest power of" << p << "that divides " << " n! " << legendre(n, p) << '\n';
  return 0;
}
