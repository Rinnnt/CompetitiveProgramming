#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

ld binpow(ld n, ll m) {
  ld ans = 1;
  while (m) {
    if (m & 1) ans = ans * n;
    n = n * n;
    m >>= 1;
  }
  return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;

    ld ev = 0;
    for (int i = 1; i <= m; i++) {
      ld f = ((ld)i) / ((ld)m);
      ld f2 = ((ld)(i - 1)) / ((ld)m);
      ev += i * (binpow(f, n) - binpow(f2, n));
    }

    cout << fixed << setprecision(15) << ev << nl;

    return 0;
}
