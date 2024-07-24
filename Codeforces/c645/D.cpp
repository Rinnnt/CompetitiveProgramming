#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<pii> edges[100001];
pii dp[100001];

pii check(int cur) {
  if (dp[cur].first != -1) return dp[cur];

  dp[cur].first = 1;
  dp[cur].second = 0;

  for (auto v : edges[cur]) {
    if (check(v.first).first + 1 > dp[cur].first) {
      dp[cur].first = check(v.first).first + 1;
      dp[cur].second = max(v.second, check(v.first).second);
    }
  }

  return dp[cur];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    dp[i].first = dp[i].second = -1;

  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back({b, i});
  }

  for (int i = 1; i <= n; i++) {
    if (check(i).first == n) {
      cout << check(i).second << nl;
      return 0;
    }
  }

  cout << -1 << nl;
  return 0;
}
