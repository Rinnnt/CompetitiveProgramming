#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> es;
  for (int i = 0; i < n; i++) {
    int s, e;
    cin >> s >> e;
    es.push_back({s, 1});
    es.push_back({e, -1});
  }

  sort(es.begin(), es.end());

  ll ans = 0;
  int level = 0;
  int prev = -1e9;
  for (auto e : es) {
    if (level) {
      ans += e.first - prev;
    }

    if (e.second == 1) {
      level++;
    } else {
      level--;
    }
    prev = e.first;
  }

  cout << ans << nl;

  return 0;
}
