#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n + 1);
  vector<ll> p(n + 1, 0);
  map<ll, ll> r;
  r[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = (p[i - 1] + a[i]) % m;
    r[p[i]]++;
  }

  ll ans = 0;
  for (auto x : r) {
    ans += (x.second * (x.second - 1)) / 2;
  }

  cout << ans << nl;

  return 0;
}

