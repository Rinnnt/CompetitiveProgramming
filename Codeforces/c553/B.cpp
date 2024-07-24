#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

ll fib[51];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < 51; i++)
    fib[i] = fib[i - 1] + fib[i - 2];

  ll n, k;
  cin >> n >> k;

  int idx = 0;
  vector<int> res(n);
  while (idx < n) {
    if (k <= fib[n - idx - 1]) {
      res[idx] = idx + 1;
      idx++;
    } else {
      k -= fib[n - idx - 1];
      res[idx] = idx + 2;
      res[idx + 1] = idx + 1;
      idx += 2;
    }
  }

  for (auto x : res) cout << x <<  " ";
  cout << nl;

  return 0;
}
