#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int a[1001];
int dp[1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int lis = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    lis = max(lis, dp[i]);
  }

  cout << lis;

  return 0;
}
