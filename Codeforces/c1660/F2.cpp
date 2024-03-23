#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int t[3][4 * 400005];

void build(int tree, int ti, int tl, int tr) {
  if (tl == tr) {
    t[tree][ti] = 0;
    return;
  }

  int mid = (tl + tr) / 2;
  build(tree, 2 * ti + 1, tl, mid);
  build(tree, 2 * ti + 2, mid + 1, tr);
  t[tree][ti] = t[tree][2 * ti + 1] + t[tree][2 * ti + 2];
}

void update(int tree, int ti, int tl, int tr, int i) {
  if (tl == tr && tl == i) {
    t[tree][ti]++;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(tree, 2 * ti + 1, tl, mid, i);
  else
    update(tree, 2 * ti + 2, mid + 1, tr, i);
  t[tree][ti] = t[tree][2 * ti + 1] + t[tree][2 * ti + 2];
}

int query(int tree, int ti, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return t[tree][ti];

  int mid = (tl + tr) / 2;
  return query(tree, 2 * ti + 1, tl, mid, l, min(mid, r)) + query(tree, 2 * ti + 2, mid + 1, tr, max(mid + 1, l), r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n;
      cin >> n;
      string s;
      cin >> s;

      int N = 2 * n + 5;
      int SHIFT = n;
      ll ans = 0;
      build(0, 0, 0, N);
      build(1, 0, 0, N);
      build(2, 0, 0, N);

      update(0, 0, 0, N, 0 + SHIFT);

      int pcnt = 0;
      int mcnt = 0;
      for (int r = 0; r < n; r++) {
        if (s[r] == '+') {
          pcnt++;
        } else {
          mcnt++;
        }

        int tree = (((mcnt - pcnt) % 3) + 3) % 3;
        ans += query(tree, 0, 0, N, 0, mcnt - pcnt + SHIFT);
        update(tree, 0, 0, N, mcnt - pcnt + SHIFT);
      }

      cout << ans << nl;

    }

    return 0;
}
