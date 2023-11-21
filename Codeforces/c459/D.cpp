#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()

typedef long long ll;

int a[1000001];
int tmp[1000001];
int cnt[1000001];
int l[1000001];
int r[1000001];
vector<int> t[4 * 1000001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = vector<int>(1, r[tl]);
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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
      cin >> a[i], tmp[i] = a[i];

    sort(tmp, tmp + n);

    for (int i = 0; i < n; i++)
      a[i] = lower_bound(tmp, tmp + n, a[i]) - tmp;

    for (int i = 0; i < n; i++)
      l[i] = ++cnt[a[i]];

    memset(cnt, 0, sizeof(cnt));
    for (int i = n - 1; i >= 0; i--)
      r[i] = ++cnt[a[i]];

    build(0, 0, n - 1);

    ll ans = 0;
    for (int i = 0; i < n; i++)
      ans += query(0, 0, n - 1, i + 1, n - 1, l[i]);

    cout << ans << nl;

    return 0;
}
