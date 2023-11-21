#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

string s;
int t[4 * 100001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = (1 << (s[tl] - 'a'));
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = t[2 * ti + 1] | t[2 * ti + 2];
}

void update(int ti, int tl, int tr, int i, int x) {
  if (tl == tr && tl == i) {
    t[ti] = x;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(2 * ti + 1, tl, mid, i, x);
  else
    update(2 * ti + 2, mid + 1, tr, i, x);
  t[ti] = t[2 * ti + 1] | t[2 * ti + 2];
}

int query(int ti, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;

  if (tl == l && tr == r)
    return t[ti];

  int mid = (tl + tr) / 2;
  return query(2 * ti + 1, tl, mid, l, min(mid, r))
       | query(2 * ti + 2, mid + 1, tr, max(l, mid + 1), r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    s.clear();
    cin >> s;

    int n = s.size();

    build(0, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
      int a, b, c;
      char ch;
      cin >> a;
      if (a == 1) {
        cin >> b >> ch;
        update(0, 0, n - 1, --b, (1 << (ch - 'a')));
      } else {
        cin >> b >> c;
        cout << __builtin_popcount(query(0, 0, n - 1, --b, --c)) << nl;
      }
    }

    return 0;
}
