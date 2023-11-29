#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pii pair<int, int>

int nums[100001];
int tmp[100001];
pii t[4 * 100001];

pii merge(pii a, pii b) {
  return {a.first + b.first, max(a.second, b.second)};
}

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = {0, 0};
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

void update(int ti, int tl, int tr, int i, bool add) {
  if (tl == tr && tl == i) {
    if (add) {
      t[ti].first = 1;
      t[ti].second++;
    } else {
      if (--t[ti].second == 0) {
        t[ti].first = 0;
      }
    }
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(ti * 2 + 1, tl, mid, i, add);
  else
    update(ti * 2 + 2, mid + 1, tr, i, add);

  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> nums[i], tmp[i] = nums[i];

  sort(tmp, tmp + n);

  for (int i = 0; i < n; i++)
    nums[i] = lower_bound(tmp, tmp + n, nums[i]) - tmp;

  build(0, 0, n - 1);
  int l = 0;
  int ans = 0;
  for (int r = 0; r < n; r++) {
    update(0, 0, n - 1, nums[r], true);
    while (t[0].first > k + 1)
      update(0, 0, n - 1, nums[l++], false);
    ans = max(ans, t[0].second);
  }

  cout << ans << nl;

  return 0;
}

