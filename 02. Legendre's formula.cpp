## এখানে (n!) এর মধ্যে সর্বোচ্চ p এর কত পাওয়ার দিয়ে ভাগ যাবে ওইটা বের করতেছে।  Complexity: O(logn).. 


#include<bits/stdc++.h>
using namespace std;

int legendre(int n, int p) {              
  int ans = 0;
  while (n) {
    ans += n / p;              // This work = (n/p^1 + n/(p^2) + ... + n/(p^n)
    n /= p;
  }
  return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p; cin >> n >> p;
    cout << "The largest power of " << p << " that divides " << n << "! is " << legendre(n, p) << '\n';
    return 0;
}
