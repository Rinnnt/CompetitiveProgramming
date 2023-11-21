#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll a[1000001];
ll s[4 * 1000001];

void build(int idx, int l, int r) {
  if (l == r) {
    s[idx] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(idx * 2 + 1, l, m);
  build(idx * 2 + 2, m + 1, r);
  s[idx] = s[idx * 2 + 1] + s[idx * 2 + 2];
}

void update(int sidx, int l, int r, int idx, ll v) {
  if (l == r && r == idx) {
    s[sidx] = v;
    return;
  }
  int m = (l + r) / 2;
  if (idx <= m) {
    update(sidx * 2 + 1, l, m, idx, v);
  } else {
    update(sidx * 2 + 2, m + 1, r, idx, v);
  }
  s[sidx] = s[sidx * 2 + 1] + s[sidx * 2 + 2];
}

ll query(int idx, int cl, int cr, int l, int r) {
  if (cl > cr || cl > r || cr < l) {
    return 0;
  }
  if (cl >= l && cr <= r) {
    return s[idx];
  }
  int m = (cl + cr) / 2;
  ll intmd1 = query(idx * 2 + 1, cl, m, l, r);
  ll intmd2 = query(idx * 2 + 2, m + 1, cr, l, r);
  return intmd1 + intmd2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, 0, n - 1);

  ll z, b, c;
  for (int i = 0; i < m + k; i++) {
    cin >> z >> b >> c;
    b--;
    if (z == 1) {
      update(0, 0, n - 1, b, c);
    } else {
      c--;
      cout << query(0, 0, n - 1, b, c) << nl;
    }
  }
  
  return 0;
}
