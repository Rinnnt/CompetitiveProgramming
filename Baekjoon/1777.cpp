#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define nl '\n'

int n;
int t[4 * 100001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = 1;
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = t[2 * ti + 1] + t[2 * ti + 2];
}

void update(int ti, int tl, int tr, int i) {
  if (tl == tr && tl == i) {
    t[ti] = 0;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(2 * ti + 1, tl, mid, i);
  else
    update(2 * ti + 2, mid + 1, tr, i);
  t[ti] = t[2 * ti + 1] + t[2 * ti + 2];
}

int query(int ti, int tl, int tr, int x) {
  if (tl == tr && x == 0) {
    return tl;
  }

  int mid = (tl + tr) / 2;
  if (x < t[2 * ti + 1])
    return query(2 * ti + 1, tl, mid, x);
  else
    return query(2 * ti + 2, mid + 1, tr, x - t[2 * ti + 1]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  build(0, 0, n - 1);
  vector<int> res(n);
  for (int i = n - 1; i >= 0; i--) {
    int idx = query(0, 0, n - 1, i - a[i]);
    res[idx] = i + 1;
    update(0, 0, n - 1, idx);
  }

  for (auto x : res)
    cout << x << " ";
  cout << nl;

  return 0;
}
