#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

ll a[250001];
ll p[250001];
ll dp[250001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll r = -1;
  ll sum = 0;
  for (ll l = 0; l < n; l++) {
    while (r < n && sum <= s)
      sum += a[++r];
    p[l] = r;
    sum -= a[l];
  }

  dp[n] = 0;
  ll ans = 0;
  for (ll i = n - 1; i >= 0; i--) {
    dp[i] = dp[p[i]] + (n - i);
    ans += dp[i];
  }

  cout << ans << nl;

  return 0;
}

