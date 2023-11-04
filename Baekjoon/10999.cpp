#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

ll nums[1000001];
ll t[4 * 1000001];
ll lazy[4 * 1000001];

void push(int ti, int tl, int tr) {
  int mid = (tl + tr) / 2;
  t[ti * 2 + 1] += lazy[ti] * (mid - tl + 1);
  t[ti * 2 + 2] += lazy[ti] * (tr - mid);
  lazy[ti * 2 + 1] += lazy[ti];
  lazy[ti * 2 + 2] += lazy[ti];
  lazy[ti] = 0;
}

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = nums[tl];
    lazy[ti] = 0;
    return;
  }

  int mid = (tl + tr) / 2;
  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
  lazy[ti] = 0;
}

void update(int ti, int tl, int tr, int l, int r, ll v) {
  if (l > r)
    return;

  if (tl == l && tr == r) {
    t[ti] += v * (r - l + 1);
    lazy[ti] += v;
    return;
  }

  push(ti, tl, tr);
  int mid = (tl + tr) / 2;
  update(ti * 2 + 1, tl, mid, l, min(mid, r), v);
  update(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r, v);
  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
}

ll query(int ti, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;

  if (l == tl && tr == r)
    return t[ti];

  push(ti, tl, tr);
  int mid = (tl + tr) / 2;
  return query(ti * 2 + 1, tl, mid, l, min(mid, r)) + query(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  build(0, 0, n - 1);

  for (int i = 0; i < m + k; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      ll d;
      cin >> d;
      update(0, 0, n - 1, --b, --c, d);
    } else
      cout << query(0, 0, n - 1, --b, --c) << nl;
  }

  return 0;
}

