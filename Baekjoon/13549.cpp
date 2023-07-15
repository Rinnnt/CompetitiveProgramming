#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int dist[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= 100000; i++) {
    dist[i] = 1e9;
  }

  dist[n] = 0;
  priority_queue<pair<int, int>> q;
  q.push({0, n});
  while (!q.empty()) {
    int cur = q.top().second;
    q.pop();
    if (cur == k) {
      break;
    }
    if (cur > 0 && dist[cur - 1] > dist[cur] + 1) {
      dist[cur - 1] = dist[cur] + 1;
      q.push({-1 * dist[cur - 1], cur - 1});
    }
    if (cur < 100000 && dist[cur + 1] > dist[cur] + 1) {
      dist[cur + 1] = dist[cur] + 1;
      q.push({-1 * dist[cur + 1], cur + 1});
    }
    if (2 * cur <= 100000 && dist[2 * cur] > dist[cur]) {
      dist[2 * cur] = dist[cur];
      q.push({-1 * dist[2 * cur], 2 * cur});
    }
  }

  cout << dist[k];

  return 0;
}
