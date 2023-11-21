#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define pll pair<ll, ll>

typedef long long ll;

ll h[200001];
ll d[200001];
ll pd[200001];
pair<pll, pll> t[4 * 200001];

pair<pll, pll> merge(pair<pll, pll> a, pair<pll, pll> b) {
  pair<pll, pll> res;

  if (a.first.first >= b.first.first)
    res.first = a.first;
  else
    res.first = b.first;

  if (a.second.first > b.second.first)
    res.second = a.second;
  else
    res.second = b.second;

  return res;
}

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = {{2 * h[tl] + pd[tl - 1], tl}, {2 * h[tl] - pd[tl - 1], tl}};
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

pair<pll, pll> query(int ti, int tl, int tr, int l, int r) {
  if (l > r)
    return {{-1e15, -1}, {-1e15, -1}};

  if (tl == l && tr == r)
    return t[ti];

  int mid = (tl + tr) / 2;
  pair<pll, pll> lq = query(2 * ti + 1, tl, mid, l, min(mid, r));
  pair<pll, pll> rq = query(2 * ti + 2, mid + 1, tr, max(l, mid + 1), r);
  return merge(lq, rq);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    pd[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> d[i];
      pd[i] = d[i] + pd[i - 1];
    }

    for (int i = n + 1; i <= 2 * n; i++)
      pd[i] = d[i - n] + pd[i -  1];

    for (int i = 1; i <= n; i++) {
      cin >> h[i];
      h[i + n] = h[i];
    }

    build(0, 1, 2 * n);

    while (m--) {
      int l, r;
      cin >> l >> r;
      pair<pll, pll> res;
      ll ans = 0;
      if (l <= r) {
        res = query(0, 1, 2 * n, r + 1, l + n - 1);
        ans = max(ans, res.first.first + merge(query(0, 1, 2 * n, r + 1, res.first.second - 1), query(0, 1, 2 * n, res.first.second + 1, l + n - 1)).second.first);
        ans = max(ans, res.second.first + merge(query(0, 1, 2 * n, r + 1, res.second.second - 1), query(0, 1, 2 * n, res.second.second + 1, l + n - 1)).first.first);
      } else {
        res = query(0, 1, 2 * n, r + 1, l - 1);
        ans = max(ans, res.first.first + merge(query(0, 1, 2 * n, r + 1, res.first.second - 1), query(0, 1, 2 * n, res.first.second + 1, l - 1)).second.first);
        ans = max(ans, res.second.first + merge(query(0, 1, 2 * n, r + 1, res.second.second - 1), query(0, 1, 2 * n, res.second.second + 1, l - 1)).first.first);
      }
      cout << ans << nl;
    }

    return 0;
}
