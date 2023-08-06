#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n;
int a[301];
int dp[301][200000];
ll mod = 998244353;

ll solve(int idx, int val) {
  if (idx > n - 2) {
    return 1;
  }
  if (dp[idx][val + 10000]) {
    return dp[idx][val + 10000];
  }
  if (val != 0) {
    return dp[idx][val + 10000] = ((solve(idx + 1, a[idx + 1] - val) + solve(idx + 1, a[idx + 1] + val)) % mod);
  } else {
    return dp[idx][val + 10000] = (solve(idx + 1, a[idx + 1]) % mod);
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    cout << solve(1, a[1]);

    return 0;
}
