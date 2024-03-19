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

      int n, m;
      cin >> n >> m;
      vector<int> as(m);
      vector<int> cnt(n + 1, 0);
      for (auto &a : as) {
        cin >> a;
        cnt[a]++;
      }

      priority_queue<int> maxq, minq;
      for (int i = 1; i < n + 1; i++) {
        maxq.push(cnt[i]);
        minq.push(-cnt[i]);
      }

      bool complete = false;
      while (!complete) {
        int mx = maxq.top();
        int mn = -minq.top();
        if (mx - mn > 2) {
          maxq.pop();
          minq.pop();
          maxq.push(mx - 1);
          minq.push(-(mn + 2));
        } else {
          complete = true;
        }
      }

      cout << maxq.top() << nl;
    }

    return 0;
}
