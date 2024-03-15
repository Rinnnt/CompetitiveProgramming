#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  n = 1000 - n;

  int ans = 0;
  for (int a : {500, 100, 50, 10, 5, 1}) {
    int cnt = n / a;
    ans += cnt;
    n -= cnt * a;
  }

  cout << ans << nl;

  return 0;
}
