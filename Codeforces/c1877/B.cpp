#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n, p;
      cin >> n >> p;
      vector<int> a(n);
      for (auto &x : a) {
        cin >> x;
      }
      vector<int> b(n);
      for (auto &x : b) {
        cin >> x;
      }

      ll ans = 0;
      map<int, int> can_use;
      priority_queue<pair<int, int>> q;
      for (int i = 0; i < n; i++) {
        q.push({-b[i], a[i]});
      }

      while (!q.empty()) {
        if (can_use.empty()) {
          ans += p;
          if (-q.top().first < p) {
            can_use[-q.top().first] += q.top().second;
          }
          q.pop();
        } else {
          ans += can_use.begin()->first;
          can_use.begin()->second -= 1;
          if (can_use.begin()->second == 0) {
            can_use.erase(can_use.begin());
          }
          if (-q.top().first < p) {
            can_use[-q.top().first] += q.top().second;
          }
          q.pop();
        }
      }

      cout << ans << nl;


    }

    return 0;
}
