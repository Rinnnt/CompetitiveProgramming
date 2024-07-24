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
      vector<int> as(n + 1), cs(n + 1), deg(n + 1, 0);
      for (int i = 1; i <= n; i++) {
        cin >> as[i];
        deg[as[i]]++;
      }
      for (int i = 1; i <= n; i++) cin >> cs[i];

      vector<int> ans;
      vector<bool> sold(n + 1, false);
      deque<int> q;
      for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
          q.push_back(i);
        }
      }
      while (!q.empty()) {
        int c = q.front();
        q.pop_front();
        sold[c] = true;
        ans.push_back(c);
        deg[as[c]]--;
        if (deg[as[c]] == 0)
          q.push_back(as[c]);
      }

      for (int i = 1; i <= n; i++) {
        if (!sold[i]) {
          int c = as[i];
          int mincost = cs[i];
          int minnode = i;
          while (c != i) {
            if (cs[c] < mincost) {
              mincost = cs[c];
              minnode = c;
            }
            c = as[c];
          }

          c = as[minnode];
          while (!sold[c]) {
            sold[c] = true;
            ans.push_back(c);
            c = as[c];
          }
        }
      }

      for (auto c : ans) cout << c << " ";
      cout << nl;

    }

    return 0;
}
