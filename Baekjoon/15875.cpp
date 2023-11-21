#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define nl '\n'

int h, w;
int parent[1000001];
int sz[1000001];

void make_set(int v) {
  parent[v] = v;
  sz[v] = 1;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b])
      swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}

vector<pair<int, int>> dxys = {
  {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

bool in_bound(int i, int j) {
  return i >= 0 && i < h && j >= 0 && j < w;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 1000001; i++)
    parent[i] = -1;

  cin >> h >> w;

  vector<pair<int, pair<int, int>>> a;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int h;
      cin >> h;
      a.push_back({h, {i, j}});
    }
  }

  sort(a.begin(), a.end());

  make_set(1000000);

  int ans = 0;
  int idx = 0;
  vector<pair<int, int>> added;
  for (int k = 0; k < a.size(); k++) {
    int h = a[k].first;
    int i = a[k].second.first;
    int j = a[k].second.second;

    make_set(i * 1000 + j);
    for (auto dxy : dxys) {
      int ni = i + dxy.first;
      int nj = j + dxy.second;
      if (in_bound(ni, nj)) {
        if (parent[ni * 1000 + nj] != -1) {
          union_sets(i * 1000 + j, ni * 1000 + nj);
        }
      } else {
        union_sets(i * 1000 + j, 1000000);
      }
    }

    if (k == a.size() - 1 || a[k].first != a[k + 1].first) {
      for (int p = idx; p <= k; p++)
        if (find_set(a[p].second.first * 1000 + a[p].second.second) != find_set(1000000))
          ans = max(ans, sz[find_set(a[p].second.first * 1000 + a[p].second.second)]);
      idx = k + 1;
    }
  }

  cout << ans << nl;


  return 0;
}

