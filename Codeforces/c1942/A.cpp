#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll t;
  cin >> t;
  while (t--) {

    int n, k;
    cin >> n >> k;

    if (k == 1) {
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << nl;
    } else if (k == n) {
      for (int i = 1; i <= n; i++) {
        cout << 1 << " ";
      }
      cout << nl;
    } else {
      cout << -1 << nl;
    }

  }

  return 0;
}
