#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q, m;
    cin >> q >> m;

    stack<int> nums;
    vector<stack<int>> stks(m, stack<int>());

    for (int i = 0; i < q; i++) {
      int t;
      cin >> t;
      if (t == 1) {
        int num;
        cin >> num;
        stks[num % m].push(nums.size());
        nums.push(num);
      } else if (t == 2) {
        if (!nums.empty()) {
          stks[nums.top() % m].pop();
          nums.pop();
        }
      } else {
        int ans = -1;
        for (int j = 0; j < m; j++) {
          if (stks[j].empty()) {
            ans = -1;
            break;
          }
          ans = max(ans, (int)(nums.size() - stks[j].top()));
        }
        cout << ans << nl;
      }
    }


    return 0;
}
