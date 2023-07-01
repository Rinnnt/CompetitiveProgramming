#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll h, w;
vector<string> b;
vector<char> rule = {'s', 'n', 'u', 'k', 'e'};
vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, 1, -1, 0};
bool dp[501][501];
bool visited[501][501];

bool dfs(int x, int y, int n) {
  if (x < 0 || x >= b.size() || y < 0 || y >= b[0].size() || b[x][y] != rule[n]) {
    return false;
  }
  if (visited[x][y]) {
    return dp[x][y];
  }
  visited[x][y] = true;
  if (b[x][y] != rule[n]) {
    dp[x][y] = false;
    return false;
  }
  if (x == h && y == w && b[x][y]) {
    dp[x][y] = true;
    return true;
  }
  for (int i = 0; i < 4; i++) {
    if (dfs(x + dx[i], y + dy[i], (n + 1) % 5)) {
      dp[x][y] = true;
      return true;
    }
  }
  dp[x][y] = false;
  return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 501; i++) {
      for (int j = 0; j < 501; j++) {
        visited[i][j] = false;
      }
    }

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
      string s;
      cin >> s;
      b.push_back(s);
    }

    h--; w--;

    if (dfs(0, 0, 0)) {
      cout << "Yes";
    } else {
      cout << "No";
    }

    return 0;
}
