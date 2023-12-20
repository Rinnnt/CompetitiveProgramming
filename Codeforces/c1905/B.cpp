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

      vector<int> deg(n + 1);

      for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
      }

      int leaves = 0;
      for (int i = 1; i <= n; i++)
        if (deg[i] == 1)
          leaves++;

      cout << (leaves + 1) / 2 << nl;
    }

    return 0;
}
