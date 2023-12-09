#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'
#define pii pair<int, int>

ll amt[200000];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  priority_queue<ll> p;
  for (ll i = 0; i < n; i++)
    p.push(-1 * i);

  priority_queue<pair<ll, pll>> q;
  for (int i = 0; i < m; i++) {
    ll t, w, s;
    cin >> t >> w >> s;
    q.push({-1 * (2 * t + 1), {w, s}});
  }

  while (!q.empty()) {
    ll t = -1 * q.top().first;
    if (t % 2) {
      ll w = q.top().second.first;
      ll s = q.top().second.second;
      if (!p.empty()) {
        amt[-1 * p.top()] += w;
        q.push({-2 * (t / 2 + s), {-1 * p.top(), 0}});
        p.pop();
      }
    } else {
      p.push(-1 * q.top().second.first);
    }
    q.pop();
  }

  for (int i = 0; i < n; i++)
    cout << amt[i] << nl;

  return 0;
}

