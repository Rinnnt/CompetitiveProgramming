#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

ll p[100001];
ll t[100001];
// 840 is the LCM of 1, 2, 3, ..., 8
ll tt[840];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, x, y, q;
    cin >> n >> x >> y;
    for (int i = 0; i < n - 1; i++) {
      cin >> p[i] >> t[i];
    }

    for (int i = 0; i < 840; i++) {
      ll ct = i;
      ct += x;
      for (int j = 0; j < n - 1; j++) {
        while (ct % p[j]) {
          ct++;
        }
        ct += t[j];
      }
      ct += y;
      tt[i] = ct - i;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
      ll s;
      cin >> s;
      cout << s + tt[s % 840] << nl;
    }

    return 0;
}
