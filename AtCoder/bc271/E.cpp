#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

pair<pair<int, int>, ll> edges[200001];
ll dist[200001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++)
    dist[i] = 1e16;
  dist[1] = 0;

  for (int i = 1; i <= m; i++) {
    cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
  }

  for (int i = 0; i < k; i++) {
    int e;
    cin >> e;
    dist[edges[e].first.second] = min(dist[edges[e].first.second], dist[edges[e].first.first] + edges[e].second);
  }

  cout << (dist[n] == 1e16 ? -1 : dist[n]) <<nl;

  return 0;
}

