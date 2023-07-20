#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll m = 0;
  for (auto &x : a) {
    cin >> x;
    m = max(m, x);
  }

  ll l = -1;
  ll r = m + 1;

  ll ans = 0;
  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    ll c = 0;
    for (auto x : a) {
      c += max(0LL, x - mid);
    }
    if (c < k) {
      ans = mid;
      r = mid;
    } else if (c > k) {
      l = mid;
    } else {
      ans = mid;
      break;
    }
  }

  cout << ans;

  return 0;
}
