#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[17];
int dp[17][200000];

int solve(int cur, int visited) {
  if (dp[cur][visited] != -1)
    return dp[cur][visited];

  dp[cur][visited] = 1;

  for (auto n : edges[cur]) {
    if ((visited & (1 << (n - 1))) == (1 << (n - 1))) continue;
    dp[cur][visited] = max(dp[cur][visited], solve(n, visited | (1 << (n - 1))) + 1);
  }
  return dp[cur][visited];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n;
      cin >> n;

      for (int i = 1; i <= n; i++) {
        edges[i].clear();
        for (int mask = 0; mask < (1 << n); mask++)
          dp[i][mask] = -1;
      }

      map<string, vector<int>> genre;
      map<string, vector<int>> writer;

      for (int i = 1; i <= n; i++) {
        string g, w;
        cin >> g >> w;
        set<int> cs;
        for (auto x : genre[g])
          cs.insert(x);
        for (auto x : writer[w])
          cs.insert(x);
        for (auto x : cs) {
          edges[x].push_back(i);
          edges[i].push_back(x);
        }
        genre[g].push_back(i);
        writer[w].push_back(i);
      }

      int res = 0;
      for (int i = 1; i <= n; i++) {
        res = max(res, solve(i, (1 << (i - 1))));
      }

      cout << n - res << nl;

    }

    return 0;
}
