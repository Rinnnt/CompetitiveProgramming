#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n;
      cin >> n;
      vector<int> as(n);
      for (auto &a : as) cin >> a;

      vector<int> ps(n + 1, 0);
      for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] ^ as[i - 1];

      vector<int> pmap(2 * n, 0);
      for (auto p : ps)
        pmap[p]++;

      ll zeros = 0;
      for (auto pc : pmap)
        zeros += (pc * 1LL * (pc - 1)) / 2;

      ll squares = 0;
      for (int i = 1; i * i < 2 * n; i++) {
        for (auto p : ps) {
          int need = (i * i) ^ p;
          if (need < 2 * n)
            squares += pmap[need];
        }
      }
      squares /= 2;

      cout << (n * 1LL * (n + 1)) / 2 - zeros - squares << nl;
    }

    return 0;
}
