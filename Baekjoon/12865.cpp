#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll dp[100005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  ll ret = 0;
  for (int j = 0; j <= k; j++) {
    dp[j] = 0;
  }
  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    for (int j = k; j >= 0; j--) {
      if (j - w >= 0) {
        dp[j] = max(dp[j], dp[j - w] + v);
        ret = max(ret, dp[j]);
      }
    }
  }
  cout << ret;
}