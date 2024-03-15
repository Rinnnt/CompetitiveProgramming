#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const ll mod = 1e9 + 7;

ll modpow(ll n, ll m) {
  ll ans = 1;
  while (m) {
    if (m % 2) ans = ans * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n, m;
      cin >> n >> m;
      vector<ll> as(n);
      for (auto &a : as) cin >> a;

      sort(as.begin(), as.end());

      vector<ll> bs(1, as[0]);
      vector<ll> cs(1, 1);
      for (int i = 1; i < n; i++) {
        if (as[i] == as[i - 1]) {
          cs[cs.size() - 1]++;
        } else {
          bs.push_back(as[i]);
          cs.push_back(1);
        }
      }

      vector<ll> ms(cs.size() + 1, 1);
      for (int i = 1; i <= cs.size(); i++)
        ms[i] = ms[i - 1] * cs[i - 1] % mod;

      ll ans = 0;
      for (int i = 0; i + m - 1 < bs.size(); i++) {
        if (bs[i] + m - 1 == bs[i + m - 1]) {
          ans += ms[(i + m - 1) + 1] * modpow(ms[(i - 1) + 1], mod - 2) % mod;
          ans %= mod;
        }
      }

      cout << ans << nl;
    }

    return 0;
}
