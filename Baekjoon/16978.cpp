#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

ll nums[100001];
ll t[4 * 100001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = nums[tl];
    return;
  }

  int mid = (tl + tr) / 2;
  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
}

void update(int ti, int tl, int tr, int i, ll v) {
  if (tl == tr && tl == i) {
    t[ti] = v;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(ti * 2 + 1, tl, mid, i, v);
  else
    update(ti * 2 + 2, mid + 1, tr, i, v);
  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
}

ll query(int ti, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;

  if (l == tl && tr == r)
    return t[ti];

  int mid = (tl + tr) / 2;
  return query(ti * 2 + 1, tl, mid, l, min(mid, r)) + query(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  build(0, 0, n - 1);

  vector<pair<int, ll>> u;
  vector<pair<int, pair<int, pair<int, int>>>> q;

  int m;
  cin >> m;
  int qidx = 0;
  for (int i = 0; i < m; i++) {
    ll a;
    cin >> a;
    if (a == 1) {
      ll b, c;
      cin >> b >> c;
      u.push_back({--b, c});
    } else {
      ll b, c, d;
      cin >> b >> c >> d;
      q.push_back({b, {qidx++, {--c, --d}}});
    }
  }

  sort(q.begin(), q.end());

  vector<ll> ans(q.size());
  int uidx = 0;
  for (auto &x : q) {
    while (uidx < x.first)
      update(0, 0, n - 1, u[uidx].first, u[uidx].second), uidx++;
    ans[x.second.first] = query(0, 0, n - 1, x.second.second.first, x.second.second.second);
  }

  for (auto x : ans)
    cout << x << nl;


  return 0;
}

