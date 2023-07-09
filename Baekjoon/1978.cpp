#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int isprime(int n) {
  if (n < 2) {
    return 0;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  int primes = 0;
  while (n--) {
    int x; 
    cin >> x;
    primes += isprime(x);
  }
  cout << primes;
}
