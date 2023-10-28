#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t, n;
  cin >> t >> n;
  deque<pair<ll, int>> minq;
  deque<pair<ll, int>> maxq;
  int l = 0;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (!minq.empty() && x < minq.back().first) minq.pop_back();
    while (!maxq.empty() && x > maxq.back().first) maxq.pop_back();
    minq.push_back({x, i});
    maxq.push_back({x, i});

    while (maxq.front().first - minq.front().first > t) {
      l += 1;
      if (minq.front().second < l) minq.pop_front();
      if (maxq.front().second < l) maxq.pop_front();
    }

    ans = max(ans, i - l + 1);
  }

  cout << ans << nl;

  return 0;
}


