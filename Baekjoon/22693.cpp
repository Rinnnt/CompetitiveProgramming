#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (true) {
      ull n;
      cin >> n;
      string M;
      cin >> M;

      if (n == 0) break;

      ull m = 0;
      ull digitval = 1;
      for (int i = M.size() - 1; i >= 0; i--) {
        if (M[i] <= '9')
          m += digitval * (M[i] - '0');
        else
          m += digitval * (10 + (M[i] - 'A'));
        digitval *= n;
      }

      map<ull, int> factors;
      for (ull i = 2; i * i <= n; i++) {
        while (n % i == 0) {
          factors[i]++;
          n /= i;
        }
      }
      if (n > 1)
        factors[n]++;

      ull zeros = 2e18;
      for (auto x : factors) {
        ull multiples = 0;
        for (ull p = x.first; p <= m; p *= x.first)
          multiples += m / p;
        zeros = min(zeros, multiples / x.second);
      }

      cout << zeros << nl;
    }

    return 0;
}
