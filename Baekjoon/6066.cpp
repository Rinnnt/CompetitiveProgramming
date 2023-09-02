#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int dp[55000];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, h;
  cin >> n >> h;
  vector<pair<int, int>> a(n);
  for (auto &x : a) {
    cin >> x.first >> x.second;
  }

  dp[0] = 0;
  for (int i = 1; i < h + 5000; i++) {
    dp[i] = 1e9;
  }

  for (auto x : a) {
    for (int i = x.first; i < h + 5000; i++) {
      dp[i] = min(dp[i], dp[i - x.first] + x.second);
    }
  }

  int ans = 1e9;
  for (int i = h; i < h + 5000; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans;

  return 0;
}
