#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF 1e9
#define MOD 1000000

ll fib[2][2];
ll mult[2][2];
ll tmp[2][2];

void matmul(ll (&a)[2][2], ll (&b)[2][2], ll (&c)[2][2]) {
  int d[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      d[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      c[i][j] = d[i][j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n;
  cin >> n;
  if (n == 0) {
    cout << 0 << nl;
    return 0;
  }
  n -= 1;

  fib[0][0] = 1;
  fib[0][1] = 1;
  fib[1][0] = 1;
  fib[1][1] = 0;

  mult[0][0] = 1;
  mult[0][1] = 0;
  mult[1][0] = 0;
  mult[1][1] = 1;

  while (n) {
    if (n & 1) {
      matmul(fib, mult, mult);
    }
    n >>= 1;
    matmul(fib, fib, fib);
  }

  cout << mult[0][0] << nl;

  return 0;
}
