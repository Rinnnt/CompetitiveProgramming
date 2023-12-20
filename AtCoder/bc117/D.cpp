#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

ll a[100001];
ll m[64];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < 61; i++) {
    ll cnt = 0;
    for (int j = 0; j < n; j++)
      if (a[j] & (1L << i))
        cnt++;

    m[i] = (1L << i) * max(cnt, n - cnt) + (i > 0 ? m[i - 1] : 0);
  }

  ll ans = 0;
  ll cur = 0;
  for (int i = 60; i >= 0; i--) {
    ll cnt = 0;
    for (int j = 0; j < n; j++)
      if (a[j] & (1L << i))
        cnt++;

    if (k & (1L << i)) {
      ans = max(ans, cur + (1L << i) * cnt + (i > 0 ? m[i - 1] : 0));
      cur += (1L << i) * (n - cnt);
    } else {
      cur += (1L << i) * cnt;
    }
  }

  cout << max(ans, cur) << nl;

  return 0;
}

