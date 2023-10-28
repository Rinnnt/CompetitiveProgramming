#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, d;
  cin >> n >> d;

  ll result = -1e10;
  deque<pair<ll, int>> q;
  q.push_back({0, -1});
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    if (!q.empty() && q.front().second + d < i) {
      q.pop_front();
    }

    ll dpi = max(x, q.front().first + x);
    result = max(result, dpi);

    while (!q.empty() && q.back().first <= dpi) {
      q.pop_back();
    }

    q.push_back({dpi, i});
  }

  cout << result << nl;

  return 0;
}


