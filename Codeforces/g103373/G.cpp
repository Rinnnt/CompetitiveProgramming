#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<tuple<int, int, int>> edges[200001];

ll solve(int a, int b) {
  if (get<2>(edges[a][b])) {
    return get<2>(edges[a][b]);
  }

  get<2>(edges[a][b]) = 1;
  int c = get<0>(edges[a][b]);
  for (int i = 0; i < edges[c].size(); i++) {
    if (get<1>(edges[a][b]) < get<1>(edges[c][i])) {
      get<2>(edges[a][b]) += solve(c, i);
    }
  }
  return get<2>(edges[a][b]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      edges[a].push_back(make_tuple(b, c, 0));
      edges[b].push_back(make_tuple(a, c, 0));
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < edges[i].size(); j++) {
        ans += solve(i, j);
      }
    }

    cout << ans;

    return 0;
}
