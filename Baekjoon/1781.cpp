#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  priority_queue<pair<int, int>> tasks;
  for (int i = 0; i < n; i++) {
    int d, r;
    cin >> d >> r;
    tasks.push({d, r});
  }

  priority_queue<int> q;
  int ld = tasks.top().first;
  int ans = 0;
  for (int t = ld; t > 0; t--) {
    while (!tasks.empty() && tasks.top().first >= t) {
      q.push(tasks.top().second);
      tasks.pop();
    }
    if (!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }

  cout << ans;

  return 0;
}
