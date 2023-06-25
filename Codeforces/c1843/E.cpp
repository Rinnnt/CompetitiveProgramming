#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define MAXN 254001

ll a[MAXN];
ll t[4 * MAXN];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

ll query(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return 0;
  }
  if (tl == l && tr == r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == pos && tr == pos) {
    t[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(2 * v, tl, tm, pos, new_val);
    } else {
      update(2 * v + 1, tm + 1, tr, pos, new_val);
    }
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll n, m;
      cin >> n >> m;

      for (int i = 1; i <= n; i++) {
        a[i] = 0;
      }

      vector<pair<int, int>> segs;

      for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
      }


      ll q;
      cin >> q;

      vector<ll> qs(q);
      for (int i = 0; i < q; i++) {
        cin >> qs[i];
      }


      ll l, r;
      l = -1;
      r = q;
      while (l + 1 < r) {
        for (int i = 0; i < q; i++) {
          a[qs[i]] = 0;
        }
        ll mid = (l + r) / 2;
        for (int i = 0; i < mid; i++) {
          a[qs[i]] = 1;
        }
        build(1, 1, n);
        bool found = false;
        for (pair p : segs) {
          if (query(1, 1, n, p.first, p.second) > (p.second - p.first + 1) / 2) {
            found = true;
            break;
          }
        }
        if (found) {
          r = mid;
        } else {
          l = mid;
        }
      }

      if (r == q) {
        for (int i = 0; i < q; i++) {
          a[qs[i]] = 1;
        }
        build (1, 1, n);
        bool found = false;
        for (pair p : segs) {
          if (query(1, 1, n, p.first, p.second) > (p.second - p.first + 1) / 2) {
            found = true;
            break;
          }
        }
        if (found) {
          cout << r << nl;
        } else {
          cout << "-1" << nl;
        }
      } else {
        cout << r << nl;
      }
    }

    return 0;
}

