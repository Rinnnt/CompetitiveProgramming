#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  deque<pair<ll, int>> q;
  q.push_back({0, -1});
  ll sum = 0;
  ll m = 1e16;
  for (int i = 0; i < n; i++) {
    ll e;
    cin >> e;
    sum += e;

    if (!q.empty() && q.front().second + k + 1 < i) {
      q.pop_front();
    }

    ll cur = q.front().first + e;
    while (!q.empty() && q.back().first > cur) {
      q.pop_back();
    }
    q.push_back({cur, i});

    if (i + k + 1 >= n) {
      m = min(m, cur);
    }
  }

  cout << sum - m << nl;

  return 0;
}


