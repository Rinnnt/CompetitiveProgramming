#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

pii vls[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> ws(n);
  int maxw = 0;
  for (auto &w : ws) {
    cin >> w;
    maxw = max(maxw, w);
  }

  for (int i = 0; i < m; i++)
    cin >> vls[i].second >> vls[i].first;

  sort(vls, vls + m);

  int maxl = 0;
  for (int i = 0; i < m; i++) {
    maxl = max(maxl, vls[i].second);
    vls[i].second = maxl;
  }


  if (maxw > vls[0].first) {
    cout << -1 << nl;
    return 0;
  }

  vector<int> perm(n);
  for (int i = 0; i < n; i++) perm[i] = i;

  ll ans = 1e15;
  do {
    vector<int> cws(n + 1, 0);
    vector<int> prefs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cws[i] = ws[perm[i - 1]];
      prefs[i] = prefs[i - 1] + cws[i];
    }
    vector<ll> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        int idx = lower_bound(vls, vls + m, make_pair(prefs[i] - prefs[j - 1], -1)) - vls;
        dp[i] = max(dp[i], dp[j] + vls[idx - 1].second);
      }
    }
    ans = min(ans, dp[n]);
  } while (next_permutation(perm.begin(), perm.end()));

  cout << ans << nl;

  return 0;
}
