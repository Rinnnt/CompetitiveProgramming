#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

ll sz[51];
ll ps[51];

ll solve(ll n, ll x) {
  if (x == 0) return 0;
  if (n == 0) return 1;

  if (x >= sz[n - 1] + 2) {
    return ps[n - 1] + 1 + solve(n - 1, x - sz[n - 1] - 2);
  } else {
    return solve(n - 1, x - 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  sz[0] = 1;
  ps[0] = 1;
  for (int i = 1; i < 51; i++) {
    sz[i] = 2 * sz[i - 1] + 3;
    ps[i] = 2 * ps[i - 1] + 1;
  }

  ll n, x;
  cin >> n >> x;

  cout << solve(n, x) << nl;

  return 0;
}

