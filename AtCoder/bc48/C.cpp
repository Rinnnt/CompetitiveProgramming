#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (auto &k : a) cin >> k;

  ll cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] + a[i - 1] > x) {
      ll extra = (a[i] + a[i - 1]) - x;
      cnt += min(extra, a[i]);
      a[i] -= min(extra, a[i]);
      if (a[i] + a[i - 1] > x) {
        ll extra = (a[i] + a[i - 1]) - x;
        a[i - 1] -= extra;
        cnt += extra;
      }
    }
  }
  cout << cnt << nl;

  return 0;
}

