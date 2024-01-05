#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pll;

#define nl '\n'

vector<ll> xs[200005];
pll dp[200005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  set<ll> cs;
  xs[0].push_back(0);
  xs[n + 1].push_back(0);
  cs.insert(n + 1);
  for (int i = 0; i < n; i++) {
    ll x, c;
    cin >> x >> c;
    xs[c].push_back(x);
    cs.insert(c);
  }
  for (int i = 1; i <= n; i++) {
    sort(xs[i].begin(), xs[i].end());
  }

  dp[0] = {0, 0};
  int prev = 0;
  for (auto c : cs) {
    ll pl = xs[prev][0];
    ll pr = xs[prev].back();
    ll cl = xs[c][0];
    ll cr = xs[c].back();
    dp[c].first = min(dp[prev].first + abs(cr - pl) + cr - cl, dp[prev].second + abs(cr - pr) + cr - cl);
    dp[c].second = min(dp[prev].first + abs(cl - pl) + cr - cl, dp[prev].second + abs(cl - pr) + cr - cl);

    prev = c;
  }

  cout << min(dp[*cs.rbegin()].first, dp[*cs.rbegin()].second) << nl;


  return 0;
}

