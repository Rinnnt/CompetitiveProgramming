#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<vector<ll>> al(254001);
ll leaves[254001];

void find_leaves(ll cur, ll parent) {
  ll ls = 1;
  for (ll child : al[cur]) {
    if (child != parent) {
      find_leaves(child, cur);
      ls += leaves[child];
    }
  }
  if (ls != 1) {
    ls -= 1;
  }
  leaves[cur] = ls;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll n;
      cin >> n;

      for (int i = 1; i < n + 1; i++) {
        vector<ll> v;
        al[i] = v;
      }

      for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
      }

      find_leaves(1, -1);

      ll q;
      cin >> q;

      for (int i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        cout << leaves[x] * leaves[y] << nl;
      }
    }

    return 0;
}

