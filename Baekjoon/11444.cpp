#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

map<ll, int> memo;
int mod = 1e9 + 7;

/**
 * F(2n-1) = F(n)F(n) + F(n-1)F(n-1)
 * F(2n-2) = F(n)F(n-1) + F(n-1)F(n-2)
 */
int fib(ll n) { 
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 1;
  }

  if (memo.count(n)) {
    return memo[n];
  }

  if (n % 2) {
    ll fn = fib((n + 1) / 2);
    ll fn1 = fib(n / 2);
    
    memo[n] = (fn * fn + fn1 * fn1) % mod;
    return memo[n];
  } else {
    ll fn = fib((n + 2) / 2);
    ll fn1 = fib(n / 2);
    ll fn2 = fib((n - 1) / 2);

    memo[n] = (fn * fn1 + fn1 * fn2) % mod;
    return memo[n];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n;
  cin >> n;

  cout << fib(n);

  return 0;
}
