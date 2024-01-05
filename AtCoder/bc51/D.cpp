#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int dist[101][101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<pii, int>> edges;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;
    edges.push_back({{a, b}, c});
  }

  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (i != j && dist[i][j] == 0)
        dist[i][j] = 1e9;
    }
  }

  for (int k = 1; k <= 100; k++) {
    for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= 100; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int cnt = 0;
  for (auto x : edges) {
    if (x.second > dist[x.first.first][x.first.second])
      cnt++;
  }

  cout << cnt << nl;

  return 0;
}

