#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &x : v)
    cin >> x;

  ll cmax = 0;
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ++cmax;
    ans += min(v[i], cmax);
    cmax = min(v[i], cmax);
  }

  cout << ans << nl;

  return 0;
}
