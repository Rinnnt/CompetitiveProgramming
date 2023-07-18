#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto &x : a) {
    cin >> x.first >> x.second;
  }
  vector<int> b(k);
  for (auto &x : b) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int idx = 0;
  ll ans = 0;
  priority_queue<int> q;
  for (int i = 0; i < b.size(); i++) {
    while (idx < a.size() && a[idx].first <= b[i]) {
      q.push(a[idx].second);
      idx++;
    }

    if (!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }

  cout << ans;

  return 0;
}
