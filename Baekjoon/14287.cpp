#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

ll nums[100001];
ll t[4 * 100001];
ll tstart[100001];
ll tend[100001];
vector<int> edges[100001];
ll timer = -1;

void euler_tour(int c, int p) {
  tstart[c] = ++timer;
  for (auto x : edges[c])
    if (x != p)
      euler_tour(x, c);
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

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    if (p != -1)
      edges[p].push_back(i);
  }

  euler_tour(1, -1);
  build(0, 0, n - 1);

  for (int j = 0; j < m; j++) {
    int q;
    cin >> q;
    if (q == 1) {
      int i, w;
      cin >> i >> w;
      update(0, 0, n - 1, tstart[i], w);
    } else {
      int i;
      cin >> i;
      cout << query(0, 0, n - 1, tstart[i], tend[i]) << nl;
    }
  }

  return 0;
}

