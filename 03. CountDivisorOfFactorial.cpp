

/* Solution approach;

-> A Simple Solution is to first compute the factorial of the given number, then count the number of divisors of the factorial. This solution is not efficient and may cause overflow due to factorial computation.
   A better solution is based on Legendre’s formula. Below are the step:

-> sln:  
1. Find all prime numbers less than or equal to n (input number). We can use Sieve Algorithm.
   Example: Let n be 6. 
            All prime numbers less than 6 are {2, 3, 5}.

2. For each prime number, p find the largest power of it that divides n!. We use Legendre’s formula for this purpose. 
   The value of largest power that divides n! is ?n/p? + ?n/(p2)? + ?n/(p3)? + …… 
   Example: Let these values be exp1, exp2, exp3,… Using the above formula, we get the below values for n = 6.
            The largest power of 2 that divides 6!, exp1 = 4.
            The largest power of 3 that divides 6!, exp2 = 2.
            The largest power of 5 that divides 6!, exp3 = 1.
            The result is (exp1 + 1) * (exp2 + 1) * (exp3 + 1) … for all prime numbers.
            Now, 
               For n = 6, the values exp1, exp2, and exp3 are 4 2 and 1 respectively (computed in above step 2).
               So our result is (4 + 1)*(2 + 1) * (1 + 1) = 30

  
Below is the implementation of the above idea.
*/


#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

vector<ull> Primes;
void sieve(int n){
    vector<bool> prime(n+1, true);
    for(int p = 2; p * p <= n; p++){
        if(prime[p]) {
            for(int i = p * 2; i <= n; i += p){
                prime[i] = false;
            }
        }
    }
    for(int p = 2; p <= n; p++){
        if (prime[p]){
            Primes.push_back(p);
        }
    }
}


ull factorialDivisors(ull n) {// Find all result of factorial number

    sieve(n);
    ull result = 1;

    for (int i = 0; i < Primes.size(); i++) {
        ull p = Primes[i];
        
        ull ans = 0;int cnt = 0;
        while (p <= n) { // Legendre's formula.
            ans += (n / p);
            p *= Primes[i];
            cnt++;
        }
        //cout << Primes[i] << " = " << cnt << '\n';
        result *= (ans + 1); // Multiply exponents of all primes less 
    }
  
    return result;
}


int32_t main() {
    
    int n; cin >> n;
    cout << factorialDivisors(n) << '\n';

    return 0;
}
