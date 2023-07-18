#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int h, w;
string b[101];
bool keys[26];
bool visited[101][101];
int ans;
vector<pair<int, int>> blocked[26];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int i, int j) {
  if (b[i][j] == '$') {
    ans++;
  } else if (b[i][j] >= 'a' && b[i][j] <= 'z') {
    if (!keys[b[i][j] - 'a']) {
      keys[b[i][j] - 'a'] = true;
      visited[i][j] = true;
      for (auto x : blocked[b[i][j] - 'a']) {
        dfs(x.first, x.second);
      }
      blocked[b[i][j] - 'a'].clear();
    }
  } else if (b[i][j] >= 'A' && b[i][j] <= 'Z') {
    if (!keys[b[i][j] - 'A']) {
      blocked[b[i][j] - 'A'].push_back({i, j});
      return;
    }
  }
  visited[i][j] = true;

  for (int k = 0; k < 4; k++) {
    int ni = i + dx[k];
    int nj = j + dy[k];
    if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj] && b[ni][nj] != '*') {
      dfs(ni, nj);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
      cin >> b[i];
      for (int j = 0; j < w; j++) {
        visited[i][j] = false;
      }
    }
    string k;
    cin >> k;
    for (int i = 0; i < 26; i++) {
      keys[i] = false;
      blocked[i].clear();
    }
    if (k != "0") {
      for (auto c : k) {
        keys[c - 'a'] = true;
      }
    }
    ans = 0;

    for (int i = 0; i < h; i++) {
      if (!visited[i][0] && b[i][0] != '*') {
        dfs(i, 0);
      }
      if (!visited[i][w - 1] && b[i][w - 1] != '*') {
        dfs(i, w - 1);
      }
    }
    for (int j = 0; j < w; j++) {
      if (!visited[0][j] && b[0][j] != '*') {
        dfs(0, j);
      }
      if (!visited[h - 1][j] && b[h - 1][j] != '*') {
        dfs(h - 1, j);
      }
    }

    cout << ans << nl;

  }

  return 0;
}
