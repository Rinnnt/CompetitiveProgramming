#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  if (n == k) {
    cout << 0;
    return 0;
  }
  int dist[100001];
  for (int i = 0; i < 100001; i++) {
    dist[i] = -1;
  }
  dist[n] = 0;
  deque<int> q;
  q.push_back(n);
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();
    if (cur > 0 && dist[cur - 1] == -1) {
      dist[cur - 1] = dist[cur] + 1;
      q.push_back(cur - 1);
      if (cur - 1 == k) {
        break;
      }
    }
    if (cur < 100000 && dist[cur + 1] == -1) {
      dist[cur + 1] = dist[cur] + 1;
      q.push_back(cur + 1);
      if (cur + 1 == k) {
        break;
      }
    }
    if (2 * cur < 100001 && dist[2 * cur] == -1) {
      dist[2 * cur] = dist[cur] + 1;
      q.push_back(2 * cur);
      if (2 * cur == k) {
        break;
      }
    }
  }

  cout << dist[k];

  return 0;
}
