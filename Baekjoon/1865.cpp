#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<tuple<int, int, int>> edges;
int dist[501];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    edges.clear();
    int n, m, w;
    cin >> n >> m >> w;
    while (m--) {
      int s, e, t;
      cin >> s >> e >> t;
      edges.push_back(make_tuple(s, e, t));
      edges.push_back(make_tuple(e, s, t));
    }
    while (w--) {
      int s, e, t;
      cin >> s >> e >> t;
      edges.push_back(make_tuple(s, e, -1 * t));
    }
    for (int i = 1; i <= n; i++) {
      dist[i] = 1e9;
    }
    dist[1] = 0;
    int x = -1;
    for (int i = 0; i < n; i++) {
      x = -1;
      for (auto edge : edges) {
        int s = get<0>(edge);
        int e = get<1>(edge);
        int t = get<2>(edge);
        if (dist[s] + t < dist[e]) {
          dist[e] = dist[s] + t;
          x = e;
        }
      }
    }

    if (x == -1) {
      cout << "NO" << nl;
    } else {
      cout << "YES" << nl;
    }
  }

  return 0;
}
