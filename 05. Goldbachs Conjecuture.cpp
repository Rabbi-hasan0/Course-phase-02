
/* 

-> It using for find a number n is equal to two prime addition:
    n = p1 + p2;
    
-> Also it used to: find minimum number of prime additon is equal to n;
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int spf[N]; //spf = small prime factor
vector<int> primes;
void sieve() {
  for(int i = 2; i < N; i++) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}
bool ok(int n) {
  for (int i = 2; i < n; i++) {
    if (spf[i] == i and spf[n - i] == n - i) {
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  for (int n = 4; n <= 20; n += 2) {
    if (ok(n)) cout << n << '\n';
  }
  return 0;
}
