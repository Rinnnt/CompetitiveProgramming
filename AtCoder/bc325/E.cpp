#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'
#define pii pair<int, int>

ll n, A, B, C;

ll d[1001][1001];
ll car[1001];
ll train[1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> A >> B >> C;

  for (int i = 1; i <= n; i++) {
    car[i] = 1e17;
    train[i] = 1e17;
    for (int j = 1; j <= n; j++)
      cin >> d[i][j];
  }

  car[1] = 0;
  priority_queue<pll> q;
  q.push({0, 1});
  while (!q.empty()) {
    ll cd = -q.top().first;
    int c = q.top().second;
    q.pop();

    for (int t = 1; t <= n; t++) {
      if (car[t] > cd + d[c][t] * A) {
        car[t] = cd + d[c][t] * A;
        q.push({-car[t], t});
      }
    }
  }

  train[n] = 0;
  q.push({0, n});
  while (!q.empty()) {
    ll cd = -q.top().first;
    int c = q.top().second;
    q.pop();

    for (int t = 1; t <= n; t++) {
      if (train[t] > cd + d[c][t] * B + C) {
        train[t] = cd + d[c][t] * B + C;
        q.push({-train[t], t});
      }
    }
  }

  ll ans = 1e17;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, car[i] + train[i]);
  }

  cout << ans << nl;

  return 0;
}

