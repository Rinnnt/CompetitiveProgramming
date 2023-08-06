#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<ll> res(10, 0);
  int mul = 1;
  int add = 0;
  while (n > 0) {
    int d = n / 10;
    int m = n % 10;
    for (int i = 0; i < m; i++) {
      res[i] += (d + 1) * mul;
    }
    res[m] += d * mul + 1 + add;
    for (int i = m + 1; i < 10; i++) {
      res[i] += d * mul;
    }
    res[0] -= mul;
    add += m * mul;
    n /= 10;
    mul *= 10;
  }

  for (auto x : res) {
    cout << x << " ";
  }

  return 0;
}
