#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

ll depth[200001];
ll t[4 * 200001];
ll tstart[200001];
ll tend[200001];
vector<int> edges[200001];
ll timer = -1;

void euler_tour(int c, int p, int d) {
  tstart[c] = ++timer;
  depth[c] = d;
  for (auto x : edges[c])
    if (x != p)
      euler_tour(x, c, d + 1);
  tend[c] = timer;
}

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = 0;
    return;
  }

  int mid = (tl + tr) / 2;
  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
}

void update(int ti, int tl, int tr, int i, ll v) {
  if (i == tl && tr == i) {
    t[ti] += v;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(ti * 2 + 1, tl, mid, i, v);
  else
    update(ti * 2 + 2, mid + 1, tr, i, v);
  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
}

ll query(int ti, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;

  if (tl == l && tr == r) {
    return t[ti];
  }

  int mid = (tl + tr) / 2;
  return query(ti * 2 + 1, tl, mid, l, min(mid, r)) + query(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  euler_tour(c, -1, 1);
  build(0, 0, n - 1);

  int q;
  cin >> q;
  for (int j = 0; j < q; j++) {
    int k;
    cin >> k;
    if (k == 1) {
      int i;
      cin >> i;
      update(0, 0, n - 1, tstart[i], 1);
    } else {
      int i;
      cin >> i;
      cout << depth[i] * query(0, 0, n - 1, tstart[i], tend[i]) << nl;
    }
  }

  return 0;
}

