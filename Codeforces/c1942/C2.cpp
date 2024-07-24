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

    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> ps(x);
    for (auto &p : ps) cin >> p;

    sort(ps.begin(), ps.end());

    ll ans = x - 2;
    for (int i = 1; i < x; i++)
      if (ps[i] - ps[i - 1] == 2LL)
        ans++;

    if (ps[x - 1] == n - 1 && ps[0] == 1LL)
      ans++;
    if (ps[x - 1] == n && ps[0] == 2LL)
      ans++;

    priority_queue<pair<ll, ll>> q;
    for (int i = 1; i < x; i++) {
      ll diff = ps[i] - ps[i - 1];
      if (diff > 2) {
        q.push({-(diff % 2), -diff});
      }
    }

    ll diff = ps[0] + n - ps[x - 1];
    if (diff > 2) {
      q.push({-(diff % 2), -diff});
    }

    while (y > 0 && !q.empty()) {
      ll diff = -q.top().second;
      q.pop();
      if (diff % 2 == 0) {
        ll can = diff / 2 - 1;
        if (y >= can) {
          y -= can;
          ans += 2 * can + 1;
        } else {
          ans += 2 * y;
          y = 0;
        }
      } else {
        ll can = min(y, diff / 2);
        y -= can;
        ans += 2 * can;
      }
    }

    cout << ans << nl;
  }

  return 0;
}
