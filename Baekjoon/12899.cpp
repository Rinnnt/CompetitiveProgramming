#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int nums[2000001];
int t[4 * 2000001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = 0;
    return;
  }

  int mid = (tl + tr) / 2;
  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
}

void update(int ti, int tl, int tr, int i) {
  if (tl == tr && tl == i) {
    t[ti]++;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(ti * 2 + 1, tl, mid, i);
  else
    update(ti * 2 + 2, mid + 1, tr, i);

  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
}

int query(int ti, int tl, int tr, int x) {
  if (tl == tr) {
    t[ti]--;
    return tl;
  }

  int ans;
  int mid = (tl + tr) / 2;
  if (x <= t[ti * 2 + 1])
    ans = query(ti * 2 + 1, tl, mid, x);
  else
    ans = query(ti * 2 + 2, mid + 1, tr, x - t[ti * 2 + 1]);

  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  build(0, 0, 2000000);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1)
      update(0, 0, 2000000, x);
    else
      cout << query(0, 0, 2000000, x) << nl;
  }

  return 0;
}

