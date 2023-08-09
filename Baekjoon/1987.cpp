#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int r, c;
string b[20];
bool visited[26];

pair<int, int> dxys[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solve(int x, int y) {
  visited[b[x][y] - 'A'] = true;
  int ans = 0;
  for (auto dxy : dxys) {
    int nx = x + dxy.first;
    int ny = y + dxy.second;
    if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[b[nx][ny] - 'A']) {
      ans = max(ans, solve(nx, ny));
    }
  }
  visited[b[x][y] - 'A'] = false;
  return ans + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> r >> c;
  for (int i = 0; i < 26; i++) {
    visited[i] = false;
  }
  for (int i = 0; i < r; i++) {
    cin >> b[i];
  }

  cout << solve(0, 0);

  return 0;
}
