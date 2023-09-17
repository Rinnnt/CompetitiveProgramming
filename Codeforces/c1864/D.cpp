#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<vector<int>> a(n, vector<int>(n, 0));
      for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
          a[i][j] = s[j] - '0';
        }
      }

      vector<vector<int>> inc(n + 1, vector<int>(n, 0));
      vector<vector<int>> dec(n + 1, vector<int>(n, 0));
      int ans = 0;

      for (int i = 0; i < n; i++) {
        int pre_sum = 0;
        for (int j = 0; j < n; j++) {
          pre_sum += inc[i][j];
          a[i][j] ^= pre_sum % 2;
          inc[i + 1][max(0, j - 1)] += inc[i][j];
          dec[i + 1][min(j + 1, n - 1)] += dec[i][j];
          if (a[i][j] == 1) {
            ans++;
            inc[i + 1][max(0, j - 1)]++;
            dec[i + 1][min(j + 1, n - 1)]++;
          }
          pre_sum -= dec[i][j];
        }
      }

      cout << ans << nl;
    }

    return 0;
}
