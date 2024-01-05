#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int dist[201][201];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 201; i++) {
    for (int j = 0; j < 201; j++) {
      dist[i][j] = (i == j ? 0 : 1e9);
    }
  }

  int n, m, r;
  cin >> n >> m >> r;

  vector<int> rs(r);
  for (auto &x : rs) cin >> x;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  vector<int> p(r);
  for (int i = 0; i < r; i++) p[i] = i + 1;

  int mn = 1e9;
  do {
    int d = 0;
    for (int i = 1; i < r; i++) {
      d += dist[rs[p[i] - 1]][rs[p[i - 1] - 1]];
    }
    mn = min(mn, d);
  } while (next_permutation(p.begin(), p.end()));

  cout << mn << nl;

  return 0;
}

