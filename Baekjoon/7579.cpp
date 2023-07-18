#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, m;
int a[101];
int c[101];
int dp[10001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 10000; j >= c[i]; j--) {
      dp[j] = max(dp[j], dp[j - c[i]] + a[i]);
    }
  }

  int ans = 0;
  while (dp[ans] < m) {
    ans++;
  }

  cout << ans;

  return 0;
}
