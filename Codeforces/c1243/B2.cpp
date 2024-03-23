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
      string sstr, tstr;
      cin >> sstr >> tstr;

      vector<char> s;
      vector<char> t;
      for (auto c : sstr) s.push_back(c);
      for (auto c : tstr) t.push_back(c);

      vector<queue<int>> sis(26, queue<int>());
      vector<queue<int>> tis(26, queue<int>());
      vector<int> tcs(26, 0);

      for (int i = 0; i < n; i++) {
        tcs[s[i] - 'a']++;
        sis[s[i] - 'a'].push(i);
      }
      for (int i = 0; i < n; i++) {
        tcs[t[i] - 'a']++;
        tis[t[i] - 'a'].push(i);
      }

      bool possible = true;
      for (auto cnt : tcs)
        if (cnt % 2)
          possible = false;

      if (!possible)
        cout << "No" << nl;
      else {
        cout << "Yes" << nl;
        vector<pii> ops;
        for (int i = 0; i < n; i++) {
          if (s[i] != t[i]) {
            while (!sis[s[i] - 'a'].empty() && sis[s[i] - 'a'].front() <= i) sis[s[i] - 'a'].pop();
            if (!sis[s[i] - 'a'].empty()) {
              int idx = sis[s[i] - 'a'].front();
              s[idx] = t[i];
              sis[s[i] - 'a'].pop();
              ops.push_back({idx, i});
              sis[t[i] - 'a'].push(idx);
            } else {
              while (!tis[s[i] - 'a'].empty() && tis[s[i] - 'a'].front() <= i) tis[s[i] - 'a'].pop();
              int idx = tis[s[i] - 'a'].front();
              t[idx] = t[i];
              tis[s[i] - 'a'].pop();
              tis[t[i] - 'a'].push(idx);
              ops.push_back({i, i});
              ops.push_back({i, idx});
            }
          }
        }

        cout << ops.size() << nl;
        for (auto op : ops) cout << op.first + 1 << " " << op.second + 1 << nl;
      }

    }

    return 0;
}
