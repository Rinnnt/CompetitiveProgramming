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
      ll n, x;
      cin >> n >> x;

      vector<ll> f(n, 0);
      vector<ll> s(n, 0);
      vector<ll> t(n, 0);
      for (int i = 0; i < n; i++) {
        cin >> f[i];
      }
      for (int i = 0; i < n; i++) {
        cin >> s[i];
      }
      for (int i = 0; i < n; i++) {
        cin >> t[i];
      }

      ll k = 0;
      ll fi = 0;
      ll si = 0;
      ll ti = 0;

      while (k != x) {
        bool ored = false;
        if (fi < f.size() && (f[fi] | x) == x) {
          k |= f[fi++];
          ored = true;
        }
        if (si < s.size() && (s[si] | x) == x) {
          k |= s[si++];
          ored = true;
        }
        if (ti < t.size() && (t[ti] | x) == x) {
          k |= t[ti++];
          ored = true;
        }
        if (!ored) {
          break;
        }
      }

      if (k == x) {
        cout << "Yes";
      } else {
        cout << "No";
      }
      cout << nl;
    }


    return 0;
}
