#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

ll a[200001];
ll f[200001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> f[i];

  sort(a, a + n);
  sort(f, f + n, greater<int>());

  ll l = -1;
  ll r = 1e18;
  while (l + 1 < r) {
    ll mid = (l + r) / 2;

    ll ck = k;
    for (int i = 0; i < n; i++) {
      ll req = mid / f[i];
      ck -= max(a[i] - req, 0LL);
    }

    if (ck >= 0) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << r << nl;

  return 0;
}

