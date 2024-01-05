#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

vector<pii> edges[100001];
ll dist[100001];

void dfs(int cur, int parent) {
  for (auto x : edges[cur])
    if (x.first != parent) {
      dist[x.first] = dist[cur] + x.second;
      dfs(x.first, cur);
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }

  int q, k;
  cin >> q >> k;

  dist[k] = 0;
  dfs(k, -1);

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << dist[x] + dist[y] << nl;
  }

  return 0;
}

