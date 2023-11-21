#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int s[100001];
pair<int, int> t[4 * 100001];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  int m = __gcd(a.first, b.first);
  return {m, (m == a.first ? a.second : 0) + (m == b.first ? b.second : 0)};
}

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = {s[tl], 1};
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

pair<int, int> query(int ti, int tl, int tr, int l, int r) {
  if (tl == l && tr == r)
    return t[ti];

  int mid = (tl + tr) / 2;
  if (r <= mid)
    return query(2 * ti + 1, tl, mid, l, r);
  if (l > mid)
    return query(2 * ti + 2, mid + 1, tr, l, r);
  pair<int, int> lq = query(2 * ti + 1, tl, mid, l, min(mid, r));
  pair<int, int> rq = query(2 * ti + 2, mid + 1, tr, max(l, mid + 1), r);
  return merge(lq, rq);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
      cin >> s[i];

    build(0, 0, n - 1);

    int t;
    cin >> t;

    while (t--) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      cout << r - l + 1 - query(0, 0, n - 1, l, r).second << nl;
    }

    return 0;
}
