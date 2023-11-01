#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

const ll MOD = 1e9 + 7;

ll nums[1000001];
ll t[4 * 1000001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = nums[tl];
    return;
  }

  int mid = (tl + tr) / 2;
  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti] = t[ti * 2 + 1] * t[ti * 2 + 2] % MOD;
}

void update(int ti, int tl, int tr, int i, ll v) {
  if (tl == tr && tl == i) {
    t[ti] = v;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(ti * 2 + 1, tl, mid, i, v);
  else
    update(ti * 2 + 2, mid + 1, tr, i, v);
  t[ti] = t[ti * 2 + 1] * t[ti * 2 + 2] % MOD;
}

ll query(int ti, int tl, int tr, int l, int r) {
  if (l > r)
    return 1;

  if (l == tl && tr == r)
    return t[ti];

  int mid = (tl + tr) / 2;
  return query(ti * 2 + 1, tl, mid, l, min(mid, r)) * query(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  build(0, 0, n - 1);

  for (int i = 0; i < m + k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      b--;
      update(0, 0, n - 1, b, c);
    } else
      cout << query(0, 0, n - 1, --b, --c) << nl;
  }

  return 0;
}

