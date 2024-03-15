#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

ll a[500001];
ll b[500001];
ll c[500001];
tuple<ll, ll, ll, ll> t[4 * 500001];

tuple<ll, ll, ll, ll> merge(tuple<ll, ll, ll, ll> l, tuple<ll, ll, ll, ll> r) {
  ll lsurplus = get<0>(l);
  ll ldeficit = get<1>(l);
  ll lcap = get<2>(l);
  ll lprod = get<3>(l);
  ll rsurplus = get<0>(r);
  ll rdeficit = get<1>(r);
  ll rcap = get<2>(r);
  ll rprod = get<3>(r);

  ll flow = min(lcap, lsurplus);
  ll rsurplus += flow;
  ll lsurplus -= flow;
  ll extra = min(rsurplus, rdeficit);
  rsurplus -= extra;
  rdeficit -= extra;

  if (flow == lcap) {
    ll lsurplus = 0;
    ll tcap = rcap;
  }

  ll remcap = lcap - flow;
  ll tcap = min(rcap, remcap);

  ll extra = min(flow, rdeficit);
  ll tcap = min(lcap - flow + rsurplus, rcap);
  ll nrsurplus = rsurplus + flow - extra;

  if (rdeficit > lcap)
    rdeficit = lcap; // rsegment is limited by lsegment's capacity

  // total capacity is min of
  // - remaining capacity of lsegment + rsegment's surplus
  // - rsegment's capacity
  ll tcap = min(lcap - rdeficit + rsurplus, rcap);

  ll tsurplus;
  ll tdeficit;
  ll tprod = lprod + rprod;
  if (lsurplus < rdeficit) {
    tprod += lsurplus;
    tsurplus = rsurplus;
    tdeficit = ldeficit + (rdeficit - lsurplus);
  } else {
    tprod += rdeficit;
    tsurplus = (lsurplus - rdeficit) + rsurplus;
    tdeficit = ldeficit;
  }
  return make_tuple(tsurplus, tdeficit, tcap, tprod);
}

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    ll produced = min(a[tl], b[tl]);
    t[ti] = make_tuple(a[tl] - produced, b[tl] - produced, c[tl], produced);
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
    t[ti] = make_tuple(a[tl] - produced, b[tl] - produced, c[tl], produced);
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

    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n - 1; i++) cin >> c[i];

    build(0, 0, n - 1);

    for (int i = 0; i < q; i++) {
      ll p, x, y, z;
      cin >> p >> x >> y >> z;
      p--;

      a[p] = x;
      b[p] = y;
      c[p] = z;

      update(0, 0, n - 1, p);
      cout << get<3>(t[0]) << nl;
    }

    return 0;
}

