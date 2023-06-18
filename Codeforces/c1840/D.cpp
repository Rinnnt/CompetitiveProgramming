#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;

      int left = -1;
      int right = 0;
      vector<int> xs(n, 0);
      for (int i = 0; i < n; i++) {
        cin >> xs[i];
        right = max(xs[i], right);
      }
      sort(xs.begin(), xs.end());

      while (left + 1 < right) {
        int mid = (left + right) / 2;

        int l = xs[0];
        int c = 1;
        for (int x : xs) {
          if (x - l > 2 * mid) {
            l = x;
            c++;
            if (c > 3) {
              break;
            }
          }
        }

        if (c > 3) {
          left = mid;
        } else {
          right = mid;
        }
      }

      cout << right << '\n';
    }

    return 0;
}
