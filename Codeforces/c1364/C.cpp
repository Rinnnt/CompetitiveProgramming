#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> as(n);
    for (auto &a : as) cin >> a;

    vector<int> bs(n, 1e6);
    if (as[0] == 1)
      bs[0] = 0;
    for (int i = 1; i < n; i++) {
      if (as[i] > as[i - 1]) {
        bs[i] = as[i - 1];
      }
    }

    bool possible = true;
    queue<int> open;
    int pmex = 0;
    for (int i = 0; i < n; i++) {
      if (bs[i] == 1e6) {
        open.push(i);
      } else {
        int nmex = as[i];
        for (int k = pmex + 1; k < nmex; k++) {
          if (open.empty()) {
            possible = false;
            break;
          } else {
            bs[open.front()] = k;
            open.pop();
          }
        }
        pmex = nmex;
      }
    }

    // actually always possible given problem constraints
    for (auto b : bs) cout << b << " ";
    cout << nl;



    return 0;
}
