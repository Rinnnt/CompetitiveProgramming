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

      int n, k, x;
      cin >> n >> k >> x;
      vector<int> as(n);
      for (auto &a : as) cin >> a;

      sort(as.begin(), as.end());

      vector<int> ps(n + 1, 0);
      for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + as[i - 1];

      int maxsum = -1e9;
      for (int i = n - k - 1; i < n; i++) {
        int neg = min(x, i + 1);
        int pos = i + 1 - neg;
        maxsum = max(maxsum, ps[pos] - (ps[i + 1] - ps[pos]));
      }

      cout << maxsum << nl;
    }

    return 0;
}
