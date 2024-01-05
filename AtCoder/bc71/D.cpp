#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  string u, d;
  cin >> u >> d;

  ll ans = 1;
  int i;
  if (u[0] == d[0]) {
    ans *= 3;
    i = 1;
  } else {
    ans *= 3 * 2;
    i = 2;
  }

  while (i < n) {
    if (u[i] == d[i]) {
      if (u[i - 1] == d[i - 1])
        ans = ans * 2 % mod;
      i++;
    } else {
      if (u[i - 1] == d[i - 1])
        ans = ans * 2 % mod;
      else
        ans = ans * 3 % mod;
      i += 2;
    }
  }

  cout << ans << nl;

  return 0;
}

