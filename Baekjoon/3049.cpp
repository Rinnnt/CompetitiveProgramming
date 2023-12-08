#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  ll ans = 0;
  for (ll i = 1; i <= n - 3; i++) {
    ans += i * (n - 3 - (i - 1));
  }

  ans *= n;

  cout << ans / 4 << nl;

  return 0;
}

