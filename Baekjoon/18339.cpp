#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define nl '\n'
#define pll pair<ll, ll>

int n, s;
ll xs[100001];
ll hs[100001];
pair<pll, pll> t[4 * 100001];

pair<pll, pll> merge(pair<pll, pll> p1, pair<pll, pll> p2) {
  pair<pll, pll> res;
  if (p1.first.first <= p2.first.first)
    res.first = p2.first;
  else
    res.first = p1.first;

  if (p1.second.first >= p2.second.first)
    res.second = p1.second;
  else
    res.second = p2.second;

  return res;
}

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = {{hs[tl] + xs[tl], tl}, {hs[tl] - xs[tl], tl}};
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

void update(int ti, int tl, int tr, int i) {
  if (tl == tr && tl == i) {
    t[ti] = {{-1e15, i}, {-1e15, i}};
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(2 * ti + 1, tl, mid, i);
  else
    update(2 * ti + 2, mid + 1, tr, i);

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

  cin >> n >> s;

  for (int i = 0; i < n; i++)
    cin >> xs[i] >> hs[i];

  build(0, 0, n - 1);
  ll ans = 0;
  s--;
  for (int i = 0; i < n - 1; i++) {
    update(0, 0, n - 1, s);

    pll l = query(0, 0, n - 1, 0, s).first;
    pll r = query(0, 0, n - 1, s, n - 1).second;

    if (l.first - xs[s] > r.first + xs[s]) {
      ans += abs(xs[s] - xs[l.second]);
      s = l.second;
    } else if (l.first - xs[s] == r.first + xs[s]) {
      if (abs(xs[s] - xs[l.second]) <= abs(xs[s] - xs[r.second])) {
        ans += abs(xs[s] - xs[l.second]);
        s = l.second;
      } else {
        ans += abs(xs[s] - xs[r.second]);
        s = r.second;
      }
    } else {
      ans += abs(xs[s] - xs[r.second]);
      s = r.second;
    }

  }

  cout << ans << nl;

  return 0;
}

