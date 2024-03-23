#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int degree[50001] = {};
vector<int> color;
vector<pii> adj[50001];
int cur_color = 1;

void dfs(int cur) {
  for (auto n : adj[cur]) {
    if (color[n.second] == -1) {
      color[n.second] = cur_color++;
      dfs(n.first);
    }
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    color.resize(m, -1);

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back({v, i});
      adj[v].push_back({u, i});
      degree[u]++;
      degree[v]++;
    }

    int onedeg = 0;
    int onenode = 0;
    for (int i = 1; i <= n; i++)
      if (degree[i] == 1) {
        onedeg++;
        onenode = i;
      }

    if (onedeg > 1 && n != 2) {
      cout << "IMPOSSIBLE" << nl;
    } else {
      if (onenode)
        dfs(onenode);
      for (int i = 1; i <= n; i++)
        dfs(i);
      for (int i = 0; i < m; i++) {
        cout << color[i] << nl;
      }
    }

    return 0;
}
