#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

ll cnt[30] = {};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
      ll t, v;
      cin >> t >> v;

      if (t == 1) {
        cnt[v]++;
      } else {
        for (int i = 29; i >= 0; i--) {
          int val = (1L << i);
          v -= val * min(cnt[i], (v / val));
        }
        if (v == 0) {
          cout << "YES" << nl;
        } else {
          cout << "NO" << nl;
        }
      }
    }



    return 0;
}
