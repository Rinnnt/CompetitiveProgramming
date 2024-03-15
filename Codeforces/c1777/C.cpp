#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int cnt[100001];
vector<int> factors[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      for (int i = 0; i < 100001; i++) {
        cnt[i] = 0;
        factors[i].clear();
      }

      int n, m;
      cin >> n >> m;
      vector<int> as(n);
      for (auto &a : as) cin >> a;

      sort(as.begin(), as.end());

      int l = 0;
      int ans = 1e9;
      int filled = 0;
      for (int r = 0; r < n; r++) {

        for (int i = 1; i * i <= as[r]; i++) {
          if (as[r] % i == 0) {
            factors[r].push_back(i);
            if (i != as[r] / i) {
              factors[r].push_back(as[r] / i);
            }
          }
        }

        for (auto factor : factors[r]) {
          if (factor <= m) {
            if (cnt[factor]++ == 0) filled++;
          }
        }

        while (filled == m) {
          ans = min(ans, as[r] - as[l]);

          for (auto factor : factors[l++]) {
            if (factor <= m) {
              if (--cnt[factor] == 0) filled--;
            }
          }
        }

      }

      if (ans == 1e9)
        cout << -1 << nl;
      else
        cout << ans << nl;

    }

    return 0;
}
