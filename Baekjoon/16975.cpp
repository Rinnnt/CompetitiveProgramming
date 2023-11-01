#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int nums[100001];
ll t[4 * 100001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = nums[tl];
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = 0;
}

void update(int ti, int tl, int tr, int l, int r, int v) {
  if (l > r)
    return;

  if (l == tl && r == tr) {
    t[ti] += v;
    return;
  }

  int mid = (tl + tr) / 2;
  update(ti * 2 + 1, tl, mid, l, min(mid, r), v);
  update(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r, v);
}

ll query(int ti, int tl, int tr, int x) {
  if (tl == tr && tl == x) {
    return t[ti];
  }

  ll ans = t[ti];

  int mid = (tl + tr) / 2;
  if (x <= mid)
    ans += query(ti * 2 + 1, tl, mid, x);
  else
    ans += query(ti * 2 + 2, mid + 1, tr, x);

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < 4 * 100001; i++)
    t[i] = 0;
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  build(0, 0, n - 1);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {

    int q;
    cin >> q;
    if (q == 1) {
      int i, j, k;
      cin >> i >> j >> k;
      update(0, 0, n - 1, --i, --j, k);
    } else {
      int x;
      cin >> x;
      cout << query(0, 0, n - 1, --x) << nl;
    }
  }

  return 0;
}

