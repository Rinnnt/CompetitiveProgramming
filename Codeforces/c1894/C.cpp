#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int nums[200001];
int st[200001][25];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n, k;
      cin >> n >> k;

      for (int i = 0; i < 25; i++)
        st[0][i] = 0;

      for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (1 <= nums[i] && nums[i] <= n)
          st[i][0] = (i - nums[i] > 0 ? i - nums[i] : i - nums[i] + n);
        else
          st[i][0] = 0;
      }

      for (int k = 1; k < 25; k++) {
        for (int i = 1; i <= n; i++) {
          st[i][k] = st[st[i][k - 1]][k - 1];
        }
      }

      int cur = n;
      for (int i = 24; i >= 0; i--) {
        if ((1 << i) <= k) {
          cur = st[cur][i];
          k -= (1 << i);
        }
      }

      cout << (cur == 0 ? "No" : "Yes") << nl;
    }

    return 0;
}
