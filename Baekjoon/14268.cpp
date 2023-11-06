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
}

void update(int ti, int tl, int tr, int l, int r, ll v) {
  if (l > r)
    return;

  if (tl == l && tr == r) {
    t[ti] += v;
    return;
  }

  int mid = (tl + tr) / 2;
  update(ti * 2 + 1, tl, mid, l, min(mid, r), v);
  update(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r, v);
}

ll query(int ti, int tl, int tr, int i) {
  if (i == tl && tr == i)
    return t[ti];

  int mid = (tl + tr) / 2;
  ll ans = t[ti];
  if (i <= mid)
    return ans + query(ti * 2 + 1, tl, mid, i);
  else
    return ans + query(ti * 2 + 2, mid + 1, tr, i);
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
      update(0, 0, n - 1, tstart[i], tend[i], w);
    } else {
      int i;
      cin >> i;
      cout << query(0, 0, n - 1, tstart[i]) << nl;
    }
  }

  return 0;
}

