#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n;
      cin >> n;
      priority_queue<pair<int, int>> a;
      vector<pair<int, int>> at;
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push({x, i});
      }
      for (int i = 0; i < 3; i++) {
        at.push_back(a.top());
        a.pop();
      }

      priority_queue<pair<int, int>> b;
      vector<pair<int, int>> bt;
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push({x, i});
      }
      for (int i = 0; i < 3; i++) {
        bt.push_back(b.top());
        b.pop();
      }

      priority_queue<pair<int, int>> c;
      vector<pair<int, int>> ct;
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c.push({x, i});
      }
      for (int i = 0; i < 3; i++) {
        ct.push_back(c.top());
        c.pop();
      }

      int ans = 0;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          for (int k = 0; k < 3; k++) {
            if (at[i].second != bt[j].second && at[i].second != ct[k].second && bt[j].second != ct[k].second) {
              ans = max(ans, at[i].first + bt[j].first + ct[k].first);
            }
          }
        }
      }

      cout << ans << nl;
    }

    return 0;
}
