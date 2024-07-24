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

    vector<pair<ll, ll>> as(n);
    for (ll i = 0; i < n; i++) {
      cin >> as[i].first;
      as[i].second = i + 1;
    }
    sort(as.begin(), as.end());

    vector<vector<pair<ll, ll>>> os(n + 1);
    for (int i = 0; i < m; i++) {
      ll x, y, z;
      cin >> x >> y >> z;
      os[x].push_back({y, z});
      os[y].push_back({x, z});
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pair<ll, ll>> ocs;

    ll cost = 0;
    for (auto o : os[as[0].second]) {
      ocs.push({-o.second, o.first});
    }
    visited[as[0].second] = true;

    for (ll i = 1; i < n; i++) {
      while (!ocs.empty() && -ocs.top().first < as[0].first + as[i].first) {
        if (visited[ocs.top().second]) ocs.pop();
        else {
          ll cc = -ocs.top().first;
          ll cn = ocs.top().second;
          ocs.pop();
          cost += cc;
          visited[cn] = true;
          for (auto o : os[cn]) {
            ocs.push({-o.second, o.first});
          }
        }
      }
      if (!visited[as[i].second]) {
        cost += as[0].first + as[i].first;
        for (auto o : os[as[i].second]) {
          ocs.push({-o.second, o.first});
        }
        visited[as[i].second] = true;
      }
    }

    cout << cost << nl;

    return 0;
}
