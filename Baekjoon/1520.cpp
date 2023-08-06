#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, m;
int h[501][501];
int dp[501][501];

bool inbounds(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> h[i][j];
    }
  }

  vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  set<int> visited;
  priority_queue<pair<int, int>> q;
  q.push({h[0][0], 0});
  visited.insert(0);
  dp[0][0] = 1;

  while (!q.empty()) {
    int cx = q.top().second / m;
    int cy = q.top().second % m;
    q.pop();
    for (int i = 0; i < dxy.size(); i++) {
      int nx = cx + dxy[i].first;
      int ny = cy + dxy[i].second;
      if (inbounds(nx, ny)) {
        if (h[nx][ny] > h[cx][cy]) {
          dp[cx][cy] += dp[nx][ny];
        } else if (h[nx][ny] < h[cx][cy]) {
          if (!visited.count(nx * m + ny)) {
            visited.insert(nx * m + ny);
            q.push({h[nx][ny], nx * m + ny});
          }
        }
      }
    }
  }

  cout << dp[n - 1][m - 1];

  return 0;
}
