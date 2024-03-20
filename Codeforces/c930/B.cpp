#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    vector<vector<vector<int>>> cs(26, vector(n, vector(26, 0)));
    for (int i = 0; i < n; i++) {
      int idx = i;
      for (int j = 0; j < n - 1; j++) {
        idx++;
        idx %= n;
        cs[s[i] - 'a'][j][s[idx] - 'a']++;
      }
    }

    vector<ld> ps(26);
    for (int i = 0; i < 26; i++) {
      ld maxp = 0;
      for (int j = 0; j < n - 1; j++) {
        int ones = 0;
        int total = 0;
        for (int k = 0; k < 26; k++) {
          total += cs[i][j][k];
          if (cs[i][j][k] == 1)
            ones++;
        }
        maxp = max(maxp, ((ld)ones) / ((ld) total));
      }
      ps[i] = maxp;
    }

    ld ans = 0;
    for (int i = 0; i < n; i++) {
      ans += ps[s[i] - 'a'] * ((ld)1 / ((ld)n));
    }

    cout << fixed << setprecision(15) << ans << nl;

    return 0;
}
