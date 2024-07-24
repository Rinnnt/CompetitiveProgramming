#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int n;
vector<int> edges[300001];
int tin[300001];
int tout[300001];
int timer = -1;
int up[300001][25];

void dfs(int c, int p) {
  tin[c] = ++timer;

  up[c][0] = p;
  for (int i = 1; i < 25; i++)
    up[c][i] = up[up[c][i - 1]][i - 1];

  for (auto x : edges[c])
    if (x != p)
      dfs(x, c);

  tout[c] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

pair<int, pii> lca(int u, int v) {
  if (is_ancestor(u, v)) {
    int tv = v;
    int vdist = 0;
    for (int i = 24; i >= 0; i--) {
      if (!is_ancestor(up[tv][i], u)) {
        vdist += (1LL << i);
        tv = up[tv][i];
      }
    }
    return {u, {0, vdist + 1}};
  }

  if (is_ancestor(v, u)) {
    int tu = u;
    int udist = 0;
    for (int i = 24; i >= 0; i--) {
      if (!is_ancestor(up[tu][i], v)) {
        udist += (1LL << i);
        tu = up[tu][i];
      }
    }
    return {v, {udist + 1, 0}};
  }

  int tu = u;
  int udist = 0;
  for (int i = 24; i >= 0; i--) {
    if (!is_ancestor(up[tu][i], v)) {
      udist += (1LL << i);
      tu = up[tu][i];
    }
  }
  int tv = v;
  int vdist = 0;
  for (int i = 24; i >= 0; i--) {
    if (!is_ancestor(up[tv][i], u)) {
      vdist += (1LL << i);
      tv = up[tv][i];
    }
  }
  return {up[tu][0], {udist + 1, vdist + 1}};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(1, 1);

  int q;
  cin >> q;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    pair<int, pii> res = lca(a, b);
    if (c <= res.second.first) {
      int dest = a;
      for (int i = 24; i >= 0; i--) {
        if ((1LL << i) <= c) {
          dest = up[dest][i];
          c -= (1LL << i);
        }
      }
      cout << dest << nl;
    } else {
      if (c >= res.second.first + res.second.second) {
        cout << b << nl;
      } else {
        c = res.second.first + res.second.second - c;
        int dest = b;
        for (int i = 24; i >= 0; i--) {
          if ((1LL << i) <= c) {
            dest = up[dest][i];
            c -= (1LL << i);
          }
        }
        cout << dest << nl;
      }
    }
  }


  return 0;
}
