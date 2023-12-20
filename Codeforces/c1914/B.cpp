#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n, k;
      cin >> n >> k;
      for (int i = n - k; i <= n; i++)
        cout << i << " ";
      for (int i = n - k - 1; i > 0; i--)
        cout << i << " ";
      cout << nl;

    }

    return 0;
}
