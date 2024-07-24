#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[5001];
int sz[5001];

int dfs(int cur, int p) {
  int cursize = 1;
  for (auto n : edges[cur])
    if (n != p)
      cursize += dfs(n, cur);
  return sz[cur] = cursize;
}

int solve(int cur, int p) {
  vector<bool> dp(5001, false);
  dp[0] = true;
  int total = 0;
  for (auto n : edges[cur]) {
    if (n != p) {
      total += sz[n];
      for (int j = 5000; j >= sz[n]; j--) {
        dp[j] = dp[j] | dp[j - sz[n]];
      }
    }
  }

  int l, r;
  if (total % 2 == 0) {
    l = total / 2;
    r = total / 2;
  } else {
    l = total / 2;
    r = l + 1;
  }

  while (!dp[l] || !dp[r]) {
    l--;
    r++;
  }

  int res = 0;
  for (auto n : edges[cur])
    if (n != p)
      res += solve(n, cur);
  return res + (l * r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      edges[p].push_back(i);
      edges[i].push_back(p);
    }

    dfs(1, 0);

    cout << solve(1, 0) << nl;

    return 0;
}
