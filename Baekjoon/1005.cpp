#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int delay[1001];
int dist[1001];
int idx;
int sorted[1001];
bool entered[1001];
vector<int> edges[1001];
vector<int> redges[1001];

void topological_sort(int cur) {
  for (auto x : edges[cur]) {
    if (!entered[x]) {
      entered[x] = true;
      topological_sort(x);
    }
  }
  sorted[idx--] = cur;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    idx = n;

    for (int i = 1; i <= n; i++) {
      cin >> delay[i];
      edges[i].clear();
      redges[i].clear();
      dist[i] = delay[i];
      entered[i] = false;
    }
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      edges[x].push_back(y);
      redges[y].push_back(x);
    }
    int w;
    cin >> w;

    for (int i = 1; i <= n; i++) {
      if (!entered[i]) {
        entered[i] = true;
        topological_sort(i);
      }
    }

    for (int i = 1; i <= n; i++) {
      for (auto x : redges[sorted[i]]) {
        dist[sorted[i]] = max(dist[sorted[i]], dist[x] + delay[sorted[i]]);
      }
    }

    cout << dist[w] << nl;

  }

  return 0;
}
