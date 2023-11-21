#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define nl '\n'

int s, e;
int dp[10001];
vector<pair<int, int>> edges[10001];

void dfs(int c) {
  if (dp[c] != -1)
    return;

  for (auto x : edges[c]) {
    dfs(x.first);
    dp[c] = max(dp[c], dp[x.first] + x.second);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n; i++)
    dp[i] = -1;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[b].push_back({a, c});
  }

  cin >> s >> e;
  dp[s] = 0;
  dfs(e);

  int ans = 0;
  vector<bool> used(n + 1);
  queue<int> q;
  q.push(e);
  used[e] = true;
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    for (auto x : edges[c])
      if (dp[x.first] + x.second == dp[c]) {
        ans++;
        if (!used[x.first]) {
          used[x.first] = true;
          q.push(x.first);
        }
      }
  }

  cout << dp[e] << nl << ans << nl;

  return 0;
}

