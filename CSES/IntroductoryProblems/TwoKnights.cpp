#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

/**
 * Number of squares attacked by knight in chess board
 * 
 * +---+---+---+---+---+---+---+---+
 * | 2 | 3 | 4 | 4 |...| 4 | 3 | 2 |
 * +---+---+---+---+---+---+---+---+
 * | 3 | 4 | 6 | 6 |...| 6 | 4 | 3 |
 * +---+---+---+---+---+---+---+---+
 * | 4 | 6 | 8 | 8 |...| 8 | 6 | 4 |
 * +---+---+---+---+---+---+---+---+
 * |...|...|...|...|...|...|...|...|
 * +---+---+---+---+---+---+---+---+
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> start = {0, 6, 28, 96};

    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      if (i <= 4) {
        cout << start[i - 1] << nl;
        continue;
      }
      ll all = i * i - 1;
      ll ans = (i - 4) * (i - 4) * (all - 8);
      ans += 4 * (i - 4) * (all - 6);
      ans += 4 * (i - 3) * (all - 4);
      ans += 8 * (all - 3);
      ans += 4 * (all - 2);
      ans /= 2;
      cout << ans << nl;
    }

    return 0;
}