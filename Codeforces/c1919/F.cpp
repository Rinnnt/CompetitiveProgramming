#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

ll a[500001];
tuple<ll, ll, ll> t[4 * 500001];
ll b[500001];

tuple<ll, ll, ll> merge(tuple<ll, ll, ll> l, tuple<ll, ll, ll> r) {
  ll surplus = get<0>(r);
  ll deficit = get<1>(l);
  ll produced = get<2>(l) + get<2>(r);

  ll extra = min(get<0>(l), get<1>(r));
  surplus += get<0>(l) - extra;
  deficit += get<1>(r) - extra;
  produced += extra;
  return make_tuple(surplus, deficit, produced);
}

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    ll produced = min(a[tl], b[tl]);
    t[ti] = make_tuple(a[tl] - produced, b[tl] - produced, produced);
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

void update(int ti, int tl, int tr, int idx) {
  if (tl == idx && tr == idx) {
    ll produced = min(a[tl], b[tl]);
    t[ti] = make_tuple(a[tl] - produced, b[tl] - produced, produced);
    return;
  }
  int mid = (tl + tr) / 2;
  if (idx <= mid)
    update(2 * ti + 1, tl, mid, idx);
  else
    update(2 * ti + 2, mid + 1, tr, idx);
  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, q, c;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n - 1; i++) cin >> c;

    build(0, 0, n - 1);

    for (int i = 0; i < q; i++) {
      ll p, x, y, z;
      cin >> p >> x >> y >> z;
      p--;

      a[p] = x;
      b[p] = y;

      update(0, 0, n - 1, p);
      cout << get<2>(t[0]) << nl;
    }

    return 0;
}

