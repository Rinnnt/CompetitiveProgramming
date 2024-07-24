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

      vector<vector<char>> b(2 * n, vector<char>(2 * n));
      for (int i = 0; i < 2 * n; i++) {
        if ((i / 2) % 2) {
          for (int j = 0; j < 2 * n; j++) {
            if ((j / 2) % 2) {
              b[i][j] = '#';
            } else {
              b[i][j] = '.';
            }
          }
        } else {
          for (int j = 0; j < 2 * n; j++) {
            if ((j / 2) % 2) {
              b[i][j] = '.';
            } else {
              b[i][j] = '#';
            }
          }
        }
      }

      for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
          cout << b[i][j];
        }
        cout << nl;
      }

    }

    return 0;
}
