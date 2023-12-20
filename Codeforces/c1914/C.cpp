#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int a[200001];
int b[200001];
int prefa[200001];
int bmax[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n, k;
      cin >> n >> k;

      for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefa[i] = prefa[i - 1] + a[i];
      }
      for (int i = 1; i <= n; i++) {
        cin >> b[i];
        bmax[i] = max(b[i], bmax[i - 1]);
      }

      int ans = 0;
      for (int i = 1; i <= n && i <= k; i++) {
        ans = max(ans, prefa[i] + (k - i) * bmax[i]);
      }

      cout << ans << nl;
    }

    return 0;
}
