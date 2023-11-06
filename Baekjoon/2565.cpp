#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

int nums[501];
int dp[501];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < 501; i++)
    nums[i] = -1;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    nums[a] = b;
  }

  int ans = 0;
  for (int i = 0; i < 501; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
      }
    }
  }

  cout << n - (ans - 1) << nl;

  return 0;
}
