#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> u(n);
  cin >> u[0];
  for (int i = 1; i < n; i++) {
    cin >> u[i];
    u[i] = min(u[i], u[i - 1]);
  }

  vector<int> v(m);
  for (auto &x : v) {
    cin >> x;
  }

  reverse(u.begin(), u.end());

  int idx = 0;
  for (int i = 0; i < m; i++) {
    if (idx >= n) {
      cout << 0 << nl;
      return 0;
    }
    idx = lower_bound(u.begin() + idx, u.end(), v[i]) - u.begin() + 1;
  }

  cout << n - (idx - 1) << nl;

  return 0;
}


