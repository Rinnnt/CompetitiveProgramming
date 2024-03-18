#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      ll n, q;
      cin >> n >> q;
      string s;
      cin >> s;

      vector<vector<ll>> cs(n + 1, vector<ll>(26, 0));

      for (ll i = 1; i < n + 1; i++) {
        for (ll j = 0; j < 26; j++) {
          cs[i][j] = cs[i - 1][j];
          if (s[i - 1] - 'a' == j) {
            cs[i][j]++;
          }
        }
      }

      vector<int> ds = manacher(s);

      while (q--) {
        ll l, r;
        cin >> l >> r;

        ll cn = r - l + 1;

        vector<ll> ccs(26);
        for (ll j = 0; j < 26; j++)
          ccs[j] = cs[r][j] - cs[l - 1][j];

        ll distinct = 0;
        for (ll i = 0; i < 26; i++)
          if (ccs[i] > 0)
            distinct++;

        if (distinct == 1) {
          cout << 0 << nl;
          continue;
        }

        l--;
        r--;

        if ((cn & 1) == 0) {
          // even
          ll li = 2 * l;
          ll ri = 2 * r;
          ll midi = (li + ri) / 2;

          if (ds[midi - 1] >= cn - 1 && ds[midi + 1] >= cn - 1) {
            cout << (cn / 2) * ((cn / 2) + 1) << nl;
          } else {
            cout << ((cn - 1) * (cn)) / 2 - 1 + (ds[midi] < cn ? cn : 0) << nl;
          }
        } else {
          // odd

          ll li = 2 * l;
          ll ri = 2 * r;
          ll midi = (li + ri) / 2;

          /*
          for (auto d : ds) cout << d << " ";
          cout << nl;
          cout << "midi " << midi << nl;
          cout << ds[midi - 2]  << nl;
          cout << ds[midi + 2]  << nl;
          cout << ds[midi]  << nl;
          */
          if (ds[midi - 2] >= cn - 2 && ds[midi + 2] >= cn - 2 && ds[midi] >= cn) {
            /*
            cout << "here" << nl;
            cout << cn << nl;
            */
            cout << ((cn - 1) / 2) * (((cn - 1) / 2) + 1) << nl;
          } else {
            cout << (cn * (cn - 1)) / 2 - 1 + (ds[midi] < cn ? cn : 0) << nl;
          }
        }
      }

    }

    return 0;
}
