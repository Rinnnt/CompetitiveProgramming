#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<vector<ll>> al(n1 + n2 + 2);
    for (int i = 0; i < n1 + n2 + 2; i++) {
      vector<ll> v;
      al[i] = v;
    }
    for (int i = 0; i < m; i++) {
      ll a, b;
      cin >> a >> b;
      al[a].push_back(b);
      al[b].push_back(a);
    }

    set<ll> visited;
    visited.clear();
    ll md1 = 0, md2 = 0;
    queue<pair<ll, ll>> q;
    q.push({1, 0});
    visited.insert(1);
    while (!q.empty()) {
      pair<ll, ll> f = q.front();
      q.pop();
      md1 = max(f.second, md1);
      for (auto x : al[f.first]) {
        if (!visited.count(x)) {
          q.push({x, 1 + f.second});
          visited.insert(x);
        }
      }
    }

    visited.clear();
    q.push({n1 + n2, 0});
    visited.insert(n1 + n2);
    while (!q.empty()) {
      pair<ll, ll> f = q.front();
      q.pop();
      md2 = max(f.second, md2);
      for (auto x : al[f.first]) {
        if (!visited.count(x)) {
          q.push({x, 1 + f.second});
          visited.insert(x);
        }
      }
    }

    cout << md1 + md2 + 1 << nl;

    return 0;
}
