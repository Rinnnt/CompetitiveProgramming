#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int a[200001];
pair<int, int> t[4 * 200001];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  return {a.second | b.second, a.first ^ b.first};
}

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = {a[tl], a[tl]};
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

void update(int ti, int tl, int tr, int i, int x) {
  if (tl == tr && tl == i) {
    t[ti] = {x, x};
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(2 * ti + 1, tl, mid, i, x);
  else
    update(2 * ti + 2, mid + 1, tr, i, x);
  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < (1 << n); i++)
      cin >> a[i];

    build(0, 0, (1 << n) - 1);

    while (m--) {
      int p, b;
      cin >> p >> b;
      update(0, 0, (1 << n) - 1, --p, b);
      if (n % 2)
        cout << t[0].first << nl;
      else
        cout << t[0].second << nl;
    }

    return 0;
}
