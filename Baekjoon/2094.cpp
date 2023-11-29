#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pll pair<ll, ll>

int n;
int ys[50001];
int rs[50001];
int t[4 * 50001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = rs[tl];
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = max(t[2 * ti + 1], t[2 * ti + 2]);
}

int query(int ti, int tl, int tr, int l, int r) {
  if (l > r)
    return -1e9 - 5;

  if (tl == l && tr == r)
    return t[ti];

  int mid = (tl + tr) / 2;
  int lq = query(2 * ti + 1, tl, mid, l, min(mid, r));
  int rq = query(2 * ti + 2, mid + 1, tr, max(mid + 1, l), r);
  return max(lq, rq);
}

string solve(int y, int x) {
  int yidx = lower_bound(ys, ys + n, y) - ys;
  int xidx = lower_bound(ys, ys + n, x) - ys;

  bool yp = yidx < n && ys[yidx] == y;
  bool xp = xidx < n && ys[xidx] == x;

  if (!yp && !xp) {
    return "maybe";
  }

  if (!yp && xp) {
    if (query(0, 0, n - 1, yidx,  xidx - 1) >= rs[xidx]) {
      return "false";
    } else {
      return "maybe";
    }
  }

  if (yp && !xp) {
    if (query(0, 0, n - 1, yidx + 1,  xidx - 1) >= rs[yidx]) {
      return "false";
    } else {
      return "maybe";
    }
  }

  if (yp && xp) {
    if (rs[xidx] > rs[yidx]) {
      return "false";
    } else {
      if (query(0, 0, n - 1, yidx + 1,  xidx - 1) >= rs[xidx]) {
        return "false";
      } else {
        if (xidx - yidx == x - y) {
          return "true";
        } else {
          return "maybe";
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ys[i] >> rs[i];
  }

  build(0, 0, n - 1);

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int y, x;
    cin >> y >> x;

    cout << solve(y, x) << nl;
  }

  return 0;
}
