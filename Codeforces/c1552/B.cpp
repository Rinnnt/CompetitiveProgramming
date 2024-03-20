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

      int n;
      cin >> n;
      vector<vector<int>> rs(n, vector<int>(5));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
          cin >> rs[i][j];
        }
      }

      int curMax = 0;
      for (int i = 1; i < n; i++) {

        int curMaxWins = 0;
        for (int j = 0; j < 5; j++)
          if (rs[curMax][j] < rs[i][j])
            curMaxWins++;

        if (curMaxWins < 3)
          curMax = i;

      }

      bool gold = true;
      for (int i = 0; i < n; i++) {
        if (i == curMax) continue;

        int curMaxWins = 0;
        for (int j = 0; j < 5; j++)
          if (rs[curMax][j] < rs[i][j])
            curMaxWins++;

        if (curMaxWins < 3)
          gold = false;
      }

      if (gold) {
        cout << curMax + 1 << nl;
      } else {
        cout << -1 << nl;
      }

    }

    return 0;
}
