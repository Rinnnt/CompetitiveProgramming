#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int mod = 1e4 + 7;
map<pair<int, int>, int> memo;

int binomial(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  if (k == 0 || n == k) {
    return 1;
  }
  if (k == 1 || k + 1 == n) {
    return n;
  }
  if (memo.count({n, k})) {
    return memo[{n, k}];
  }
  ll ans = 0;
  int m = n / 2;
  for (int i = 0; i < (n - m) + 1; i++) {
    ans = (ans + binomial(m, k - (n - m) + i) * binomial(n - m, i)) % mod;
  }
  memo[{n, k}] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  cout << binomial(n, k);

  return 0;
}
