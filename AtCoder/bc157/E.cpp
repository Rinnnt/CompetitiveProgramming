#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

string s;
int t[4 * 500001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = (1 << (s[tl] - 'a'));
    return;
  }

  int mid = (tl + tr) / 2;
  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti] = t[2 * ti + 1] | t[2 * ti + 2];
}

void update(int ti, int tl, int tr, int i, char v) {
  if (tl == tr && tl == i) {
    t[ti] = (1 << (v - 'a'));
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(ti * 2 + 1, tl, mid, i, v);
  else
    update(ti * 2 + 2, mid + 1, tr, i, v);

  t[ti] = t[2 * ti + 1] | t[2 * ti + 2];
}

int query(int ti, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;

  if (l == tl && r == tr)
    return t[ti];

  int mid = (tl + tr) / 2;
  int q1 = query(2 * ti + 1, tl, mid, l, min(r, mid));
  int q2 = query(2 * ti + 2, mid + 1, tr, max(l, mid + 1), r);
  return q1 | q2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  cin >> s;
  build(0, 0, n - 1);

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      char c;
      cin >> i >> c;
      update(0, 0, n - 1, --i, c);
    } else {
      int l, r;
      cin >> l >> r;
      cout << __builtin_popcount(query(0, 0, n - 1, --l, --r)) << nl;
    }
  }

  return 0;
}

