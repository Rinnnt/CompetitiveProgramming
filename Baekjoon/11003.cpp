#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, l;
  cin >> n >> l;

  priority_queue<pair<int, int>> q;
  for (int r = 0; r < n; r++) {
    int x;
    cin >> x;
    q.push({-x, r});

    while (!q.empty() && q.top().second + l <= r) {
      q.pop();
    }

    cout << -q.top().first << " ";
  }

  return 0;
}


