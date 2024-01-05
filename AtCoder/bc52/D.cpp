#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  for (auto &k : x) cin >> k;

  ll ans = 0;
  for (int i = 1; i < n; i++) {
    if ((x[i] - x[i - 1]) * a > b) {
      ans += b;
    } else {
      ans += (x[i] - x[i - 1]) * a;
    }
  }

  cout << ans << nl;

  return 0;
}

