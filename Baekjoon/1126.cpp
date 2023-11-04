#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

#define DIFFRANGE 500000

ll dp[DIFFRANGE + 1] = {};
ll tmp[DIFFRANGE + 1] = {};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < DIFFRANGE + 1; i++)
      tmp[i] = dp[i];
    tmp[a[j]] = max(tmp[a[j]], a[j]);

    for (int i = 0; i < DIFFRANGE + 1; i++) {
      if (dp[i]) {
        if (i + a[j] <= DIFFRANGE)
          tmp[i + a[j]] = max(tmp[i + a[j]], dp[i] + a[j]);
        if (a[j] <= i)
          tmp[i - a[j]] = max(tmp[i - a[j]], dp[i]);
        else
          tmp[a[j] - i] = max(tmp[a[j] - i], dp[i] - i + a[j]);
      }
    }

    for (int i = 0; i < DIFFRANGE + 1; i++)
      dp[i] = max(dp[i], tmp[i]);
  }

  cout << (dp[0] ? dp[0] : -1) << nl;

  return 0;
}
