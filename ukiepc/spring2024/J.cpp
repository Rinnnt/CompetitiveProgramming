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
    map<string, map<string, int>> cnt;
    for (int i = 0; i < n; i++) {
      string g, s;
      cin >> g >> s;
      cnt[g][s]++;
    }

    int ans = 0;
    for (auto g : cnt) {
      int t = 0;
      for (auto s : g.second) {
        t = max(t, s.second);
      }
      ans += t;
    }

    cout << ans << nl;

    return 0;
}
