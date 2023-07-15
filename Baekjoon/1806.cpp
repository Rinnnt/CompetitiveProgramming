#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, s;
  cin >> n >> s;

  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  int l = 0;
  int sum = 0;
  int res = 1e9;
  for (int r = 0; r < n; r++) {
    sum += a[r];
    while (sum >= s) {
      res = min(res, r - l + 1);
      sum -= a[l++];
    }
  }

  if (res == 1e9) {
    cout << 0;
  } else {
    cout << res;
  }

  return 0;
}
