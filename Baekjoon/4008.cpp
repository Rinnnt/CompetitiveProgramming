#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define nl '\n'

ll A, B, C;
ll x[1000001];
ll p[1000001];
ll dp[1000001];

ll m(ll i) {
  return -2 * A * p[i];
}

ll c(ll i) {
  return A * p[i] * p[i] - B * p[i] + dp[i];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  cin >> A >> B >> C;

  p[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    p[i] = p[i - 1] + x[i];
  }

  deque<int> d;
  d.push_back(0);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    while (d.size() >= 2
        && m(d[0]) * p[i] + c(d[0])
        <= m(d[1]) * p[i] + c(d[1]))
      d.pop_front();

    dp[i] = A * p[i] * p[i] + B * p[i] + C
      + m(d[0]) * p[i] + c(d[0]);

    while (d.size() >= 2
        && (c(d.back()) - c(i)) * (m(i) - m(d[d.size() - 2]))
        <= (c(d[d.size() - 2]) - c(i)) * (m(i) - m(d.back())))
      d.pop_back();
    d.push_back(i);
  }

  cout << dp[n] << nl;

  return 0;
}
