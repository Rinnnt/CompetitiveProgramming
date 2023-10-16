#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

// hungarian algorithm
// https://github.com/kth-competitive-programming/kactl/blob/main/kactl.pdf
pair<int, vector<int>> hungarian(const vector<vector<int>> &a) {
  if (a.empty()) return {0, {}};
  int n = a.size() + 1, m = a[0].size() + 1;
  vector<int> u(n), v(m), p(m), ans(n - 1);
  for (int i = 1; i < n; i++) {
    p[0] = i;
    int j0 = 0;
    vector<int> dist(m, INT_MAX), pre(m, -1);
    vector<bool> done(m + 1);
    do {
      done[j0] = true;
      int i0 = p[j0], j1, delta = INT_MAX;
      for (int j = 1; j < m; j++) {
        if (!done[j]) {
          auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
          if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
          if (dist[j] < delta) delta = dist[j], j1 = j;
        }
      }
      for (int j = 0; j < m; j++) {
        if (done[j]) u[p[j]] += delta, v[j] -= delta;
        else dist[j] -= delta;
      }
      j0 = j1;
    } while (p[j0]);
    while (j0) {
      int j1 = pre[j0];
      p[j0] = p[j1], j0 = j1;
    }
  }
  for (int j = 1; j < m; j++) if (p[j]) ans[p[j] - 1] = j - 1;
  return {-v[0], ans};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> cost(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> cost[i][j];
    }
  }

  auto ans = hungarian(cost);

  cout << ans.first;

}
