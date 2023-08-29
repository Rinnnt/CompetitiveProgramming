#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

string board[2001];
bool viewed[2001][2001];
int d[2001][2001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
      cin >> board[i];
      for (int j = 0; j < w; j++) {
        viewed[i][j] = false;
        d[i][j] = -1;
      }
    }
    pair<int, int> start, end;
    for (int i = 0; i < h; i++) {
      bool attacked = false;
      int lo = -1;
      for (int j = 0; j < w; j++) {
        if (board[i][j] == 'S') {
          start = {i, j};
        }
        if (board[i][j] == 'G') {
          end = {i, j};
          board[i][j] = '.';
        }
        if (attacked) {
          viewed[i][j] = true;
        }
        if (board[i][j] == '>' || board[i][j] == '^' || board[i][j] == 'v' || board[i][j] == '<' || board[i][j] == '#') {
          attacked = false;
          if (board[i][j] == '>') {
            attacked = true;
          }
          if (board[i][j] == '<') {
            for (int k = j - 1; k > lo; k--) {
              viewed[i][k] = true;
            }
          }
          lo = j;
        }
      }
    }
    for (int j = 0; j < w; j++) {
      bool attacked = false;
      int lo = -1;
      for (int i = 0; i < h; i++) {
        if (attacked) {
          viewed[i][j] = true;
        }
        if (board[i][j] == '>' || board[i][j] == '^' || board[i][j] == 'v' || board[i][j] == '<' || board[i][j] == '#') {
          attacked = false;
          if (board[i][j] == 'v') {
            attacked = true;
          }
          if (board[i][j] == '^') {
            for (int k = i - 1; k > lo; k--) {
              viewed[k][j] = true;
            }
          }
          lo = i;
        }
      }
    }

    vector<pair<int, int>> dxy = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    q.push({start.first, start.second});
    d[start.first][start.second] = 0;
    visited.insert({start.first, start.second});

    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      if (i == end.first && j == end.second) {
        break;
      }
      q.pop();
      for (int k = 0; k < dxy.size(); k++) {
        int ni = i + dxy[k].first;
        int nj = j + dxy[k].second;
        if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited.count({ni, nj}) && board[ni][nj] == '.' && !viewed[ni][nj]) {
          q.push({ni, nj});
          d[ni][nj] = d[i][j] + 1;
        }
      }
    }

    cout << d[end.first][end.second];
    
    return 0;
}
