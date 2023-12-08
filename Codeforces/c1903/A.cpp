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

      vector<int> a(n);
      for (auto &x : a)
        cin >> x;

      bool sorted = true;
      for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
          sorted = false;

      string ans = "NO";

      if (k > 1 || sorted)
        ans = "YES";

      cout << ans << nl;
    }

    return 0;
}
