#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

pair<ll, ll> t[4 * 100001];
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
    t[ti] = {0, 0};
    return;
  }

  int mid = (tl + tr) / 2;
  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti].second = t[ti * 2 + 1].second + t[ti * 2 + 2].second;
}

void update_up(int ti, int tl, int tr, int i, ll v) {
  if (i == tl && tr == i) {
    t[ti].second += v;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update_up(ti * 2 + 1, tl, mid, i, v);
  else
    update_up(ti * 2 + 2, mid + 1, tr, i, v);
  t[ti].second = t[ti * 2 + 1].second + t[ti * 2 + 2].second;
}

void update_down(int ti, int tl, int tr, int l, int r, ll v) {
  if (l > r)
    return;

  if (tl == l && tr == r) {
    t[ti].first += v;
    return;
  }

  int mid = (tl + tr) / 2;
  update_down(ti * 2 + 1, tl, mid, l, min(mid, r), v);
  update_down(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r, v);
}

ll query_up(int ti, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;

  if (tl == l && tr == r) {
    return t[ti].second;
  }

  int mid = (tl + tr) / 2;
  return query_up(ti * 2 + 1, tl, mid, l, min(mid, r)) + query_up(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r);
}

ll query_down(int ti, int tl, int tr, int i) {
  if (i == tl && tr == i)
    return t[ti].first;

  int mid = (tl + tr) / 2;
  ll ans = t[ti].first;
  if (i <= mid)
    return ans + query_down(ti * 2 + 1, tl, mid, i);
  else
    return ans + query_down(ti * 2 + 2, mid + 1, tr, i);
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

  bool up = false;
  for (int j = 0; j < m; j++) {
    int q;
    cin >> q;
    if (q == 1) {
      int i, w;
      cin >> i >> w;
      if (up)
        update_up(0, 0, n - 1, tstart[i], w);
      else
        update_down(0, 0, n - 1, tstart[i], tend[i], w);
    } else if (q == 2) {
      int i;
      cin >> i;
      cout << query_up(0, 0, n - 1, tstart[i], tend[i]) + query_down(0, 0, n - 1, tstart[i]) << nl;
    } else {
      up = !up;
    }
  }

  return 0;
}

