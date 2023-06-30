#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int dist[100][100];
bool visited[100][100];

class MazeMaker {
public:
  double longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) {
    for (int i = 0; i < maze.size(); i++) {
      for (int j = 0; j < maze[i].size(); j++) {
        dist[i][j] = -1;
        visited[i][j] = false;
      }
    }

    deque<int> mvs;
    deque<pair<int, int>> q;

    q.push_back({startRow, startCol});
    mvs.push_back(0);
    visited[startRow][startCol] = true;

    while (!q.empty()) {
      pair<int, int> pos = q.front();
      q.pop_front();
      int m = mvs.front();
      dist[pos.first][pos.second] = m;
      mvs.pop_front();
      for (int i = 0; i < moveRow.size(); i++) {
        int nr = pos.first + moveRow[i];
        int nc = pos.second + moveCol[i];
        if (0 <= nr && nr < maze.size() && 0 <= nc && nc < maze[nr].size() && maze[nr][nc] == '.' && !visited[nr][nc]) {
          q.push_back({nr, nc});
          mvs.push_back(m + 1);
          visited[nr][nc] = true;
        }
      }
    }

    bool impossible = false;
    int maxdist = -1;
    for (int i = 0; i < maze.size(); i++) {
      for (int j = 0; j < maze[i].size(); j++) {
        if (maze[i][j] == '.') {
          if (dist[i][j] == -1) {
            impossible = true;
            break;
          }
          maxdist = max(dist[i][j], maxdist);
        }
      }
    }

    if (impossible) {
      return -1;
    } else {
      return maxdist;
    }
  }
};