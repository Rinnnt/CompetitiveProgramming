#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int n;
int m[1000][1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      cin >> n;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cin >> m[i][j];
        }
      }

      bool pos = true;

      vector<int> a(n);
      for (int i = 0; i < n; i++) {
        int r = (1 << 30) - 1;
        for (int j = 0; j < n; j++)
          if (j != i) r &= m[i][j];
        a[i] = r;
      }

      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (i != j)
            if (m[i][j] != (a[i] | a[j]))
              pos = false;

      if (pos) {
        cout << "YES" << nl;
        for (auto x : a)
          cout << x << " ";
        cout << nl;
      } else {
        cout << "NO" << nl;
      }
    }

    return 0;
}
