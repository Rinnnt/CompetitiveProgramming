#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  cout << fixed << setprecision(15);

  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  ld mn = 1e18;
  ld mx = -1e18;

  sort(a.begin(), a.end());

  int m = lower_bound(a.begin(), a.end(), 0) - a.begin();

  vector<int> y;
  for (int i = 0; i < m; i++) {
    if (i < 3 || m - i <= 3)
      y.push_back(a[i]);
  }
  for (int i = m; i < n; i++) {
    if (i - m < 3 || n - i <= 3)
      y.push_back(a[i]);
  }

  n = y.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        ld res = 1. * (y[i] + y[j] + y[k]) / y[i] / y[j] / y[k];
        if (res < mn) mn = res;
        if (res > mx) mx = res;
      }
    }
  }

  cout << mn << nl;
  cout << mx << nl;

  return 0;
}

