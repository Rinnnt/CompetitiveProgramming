#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<int> edges[51];
double a[51];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(6);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    edges[i].clear();
    a[i] = 0.0;
  }
  a[1] = 100.0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u < v) {
      edges[u].push_back(v);
    } else {
      edges[v].push_back(u);
    }
  }

  double ans = 0.0;
  for (int i = 1; i <= n; i++) {
    if (edges[i].empty()) {
      ans = max(ans, a[i]);
    } else {
      double k = edges[i].size();
      for (auto x : edges[i]) {
        a[x] += a[i] / k;
      }
    }
  }

  cout << ans;

  return 0;
}
