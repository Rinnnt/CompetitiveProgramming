#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto &x : a) {
    cin >> x.first >> x.second;
  }

  priority_queue<pair<ll, pair<int, int>>> q;
  ll idx = 0;
  ll t = 0;
  ll ans = 0;
  int left = 0;
  while (idx < n && q.size() < k) {
    q.push({-1 * (a[idx].second + t), {idx, a[idx].first}});
    idx++;
  }
  while (left < n) {
    t = -1 * q.top().first;
    stack<int> free;
    while (!q.empty() && -1 * q.top().first == t) {
      free.push(q.top().second.first);
      ans += 1LL * ++left * q.top().second.second;
      q.pop();
    }
    while (idx < n && !free.empty()) {
      q.push({-1 * (a[idx].second + t), {free.top(), a[idx].first}});
      idx++;
      free.pop();
    }
  }
  
  cout << ans; 

  return 0;
}
