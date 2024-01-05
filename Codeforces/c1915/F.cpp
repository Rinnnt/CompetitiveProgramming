#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define all(x) x.begin(), x.end()

typedef long long ll;

pair<int, int> a[200001];
vector<int> t[4 * 200001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = vector<int>(1, a[tl].second);
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti].resize(t[2 * ti + 1].size() + t[2 * ti + 2].size());
  merge(all(t[2 * ti + 1]), all(t[2 * ti + 2]), t[ti].begin());
}

int query(int ti, int tl, int tr, int l, int r, int x) {
  if (l > r)
    return 0;

  if (tl == l && tr == r)
    return lower_bound(t[ti].begin(), t[ti].end(), x) - t[ti].begin();

  int mid = (tl + tr) / 2;
  return query(2 * ti + 1, tl, mid, l, min(mid, r), x)
    + query(2 * ti + 2, mid + 1, tr, max(l, mid + 1), r, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n;
      cin >> n;
      for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
      }
      sort(a, a + n);

      build(0, 0, n - 1);

      ll ans = 0;
      for (int i = 0; i < n; i++) {
        ans += query(0, 0, n - 1, i + 1, n - 1, a[i].second);
      }

      cout << ans << nl;
    }

    return 0;
}
