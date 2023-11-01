#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int nums[100001];
pair<int, int> t[4 * 100001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = {nums[tl], nums[tl]};
    return;
  }

  int mid = (tl + tr) / 2;
  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti] = {min(t[ti * 2 + 1].first, t[ti * 2 + 2].second), max(t[ti * 2 + 1].second, t[ti * 2 + 2].second)};
}

void update(int ti, int tl, int tr, int i, int v) {
  if (tl == tr && tl == i) {
    nums[i] = v;
    t[ti] = {v, v};
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(ti * 2 + 1, tl, mid, i, v);
  else
    update(ti * 2 + 2, mid + 1, tr, i, v);

  t[ti] = {min(t[ti * 2 + 1].first, t[ti * 2 + 2].first), max(t[ti * 2 + 1].second, t[ti * 2 + 2].second)};
}

pair<int, int> query(int ti, int tl, int tr, int l, int r) {
  if (l == tl && r == tr)
    return t[ti];

  pair<int, int> res = {1e9, -1e9};
  int mid = (tl + tr) / 2;
  if (l <= mid) {
    pair<int, int> lr = query(ti * 2 + 1, tl, mid, l, min(mid, r));
    res.first = min(res.first, lr.first);
    res.second = max(res.second, lr.second);
  }
  if (r > mid) {
    pair<int, int> rr = query(ti * 2 + 2, mid + 1, tr, max(mid + 1, l), r);
    res.first = min(res.first, rr.first);
    res.second = max(res.second, rr.second);
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
      nums[i] = i;

    build(0, 0, n - 1);
    for (int i = 0; i < k; i++) {
      int q, a, b;
      cin >> q >> a >> b;

      if (q) {
        pair<int, int> res = query(0, 0, n - 1, a, b);
        if (res.first == a && res.second == b)
          cout << "YES" << nl;
        else
          cout << "NO" <<nl;
      } else {
        int numa = nums[a];
        int numb = nums[b];
        update(0, 0, n - 1, a, numb);
        update(0, 0, n - 1, b, numa);
      }
    }
  }

  return 0;
}

