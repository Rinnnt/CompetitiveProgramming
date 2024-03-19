#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> fs(n);
    vector<int> fis(n + 1, -1);
    vector<int> fcs(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> fs[i];
      fis[fs[i]] = i;
      fcs[fs[i]]++;
    }

    vector<int> bs(m);
    for (auto &b : bs) cin >> b;

    int possible = 0;
    vector<int> as;
    for (auto b : bs) {
      if (fis[b] == -1) {
        possible = -1;
        break;
      }

      if (fcs[b] > 1) {
        possible = 1;
      }

      as.push_back(fis[b]);
    }

    if (possible == -1) {
      cout << "Impossible" << nl;
    } else if (possible == 1) {
      cout << "Ambiguity" << nl;
    } else {
      cout << "Possible" << nl;
      for (auto a : as) cout << a + 1 << " ";
      cout << nl;
    }

    return 0;
}
