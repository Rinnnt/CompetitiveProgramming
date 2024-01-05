#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 998244353;

ll dp[2000001];
ll prefix_product_odds[1000001];

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

  dp[0] = 1;
  dp[1] = 2;
  for (int i = 2; i < 2000001; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  }
  prefix_product_odds[0] = 1;
  for (int i = 1; i <= 1000000; i++) {
    prefix_product_odds[i] = prefix_product_odds[i - 1] * dp[2 * i - 1] % mod;
  }

  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;

    int a = min(h, w);
    int b = max(h, w);

    ll ans = 1;
    ans = ans * prefix_product_odds[a] % mod;
    ans = ans * prefix_product_odds[a] % mod;
    ans = ans * modpow(dp[2 * a], b - a) % mod;

    cout << ans << nl;
  }

  return 0;
}

