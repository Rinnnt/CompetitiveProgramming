#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

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
  ll ans = binomial(n - 1, k - 1) + binomial(n - 1, k);
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
