#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const ll mod = 1e9 + 7;

ll dp[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, m;
  cin >> n >> m;

  vector<ll> xs(n);
  vector<ll> ys(m);
  for (auto &x : xs) cin >> x;
  for (auto &y : ys) cin >> y;

  ll multiplier = 0;
  for (int i = 1; i < m; i++) {
    multiplier += (ys[i] - ys[i - 1]) * ((m - i) * i % mod) % mod;
    multiplier %= mod;
  }

  dp[0] = 0;
  dp[1] = multiplier * (xs[1] - xs[0]);
  for (int i = 2; i < n; i++) {
    dp[i] = (2 * dp[i - 1] % mod - dp[i - 2]) + i * multiplier % mod * (xs[i] - xs[i - 1]) % mod;
    dp[i] %= mod;
  }

  cout << (dp[n - 1] + mod) % mod << nl;


  return 0;
}

