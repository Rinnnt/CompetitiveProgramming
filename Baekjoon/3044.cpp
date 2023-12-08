#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

bool over = false;
bool cyclic = false;
bool reachable[10001];
bool visited[10001];
ll tin[10001];
ll tout[10001];
ll dp[10001];
vector<int> edges[10001];
const ll mod = 1000000000;
ll timer = -1;

ll solve(int cur) {
  tin[cur] = ++timer;

  ll ret = cur == 2;
  for (auto n : edges[cur]) {
    if (!reachable[n]) continue;
    if (tout[n] <= timer) {
      ret += dp[n];
    } else {
      if (tin[n] <= timer) {
        if (tin[2] == mod || tin[n] <= tin[2])
          cyclic = true;
      } else {
        ret += solve(n);
      }
    }
    if (ret >= mod) {
      ret %= mod;
      over = true;
    }
  }

  tout[cur] = timer;
  return dp[cur] = ret;
}

bool dfs(int cur) {
  visited[cur] = true;
  reachable[cur] = cur == 2;
  for (auto n : edges[cur]) {
    if (!visited[n])
      dfs(n);
    reachable[cur] = reachable[cur] || reachable[n];
  }
  return reachable[cur];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= 10000; i++) {
    visited[i] = false;
    reachable[i] = false;
    tin[i] = mod;
    tout[i] = mod;
    dp[i] = 0;
    edges[i].clear();
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
  }

  dfs(1);
  if (!reachable[2]) {
    cout << 0 << nl;
  } else {
    ll ans = solve(1);

    if (cyclic) {
      cout << "inf" << nl;
    } else {
      if (over)
        cout << to_string(ans + mod).substr(to_string(ans + mod).size() - 9, 9) << nl;
      else
        cout << ans << nl;
    }
  }

  return 0;
}

