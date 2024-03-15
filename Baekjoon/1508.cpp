#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> xs(k);
  for (auto &x : xs) cin >> x;

  int l = 0;
  int r = 1e9;
  while (l + 1 < r) {
    int mid = (l + r) / 2;

    vector<bool> ts(k, false);
    int prev = -1e9;
    int idx = 0;
    int cnt = 0;
    while (cnt < m) {
      while (idx < k && prev + mid > xs[idx]) {
        idx++;
      }
      if (idx >= k) break;
      ts[idx] = true;
      prev = xs[idx];
      cnt++;
    }

    if (idx < k)
      l = mid;
    else
      r = mid;
  }

  vector<bool> ts(k, false);
  int prev = -1e9;
  int idx = 0;
  int cnt = 0;
  while (cnt < m) {
    while (idx < k && prev + l > xs[idx]) {
      idx++;
    }
    if (idx >= k) break;
    ts[idx] = true;
    prev = xs[idx];
    cnt++;
  }

  for (int i = 0; i < k; i++)
    cout << (ts[i] ? 1 : 0);
  cout << nl;

  return 0;
}
