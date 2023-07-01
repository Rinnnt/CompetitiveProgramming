#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll dp[101][101][52];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 1, 2, 2 ,1, -1, -2, -2, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1, -2, -1, 1, 2, 2, 1, -1, -2};
int bsize;
vector<int> endpos;

class ChessMetric {
public:
  ll solve(int x, int y, int numMoves) {
    if (numMoves == 0){ 
      if (x == endpos[0] && y == endpos[1]) {
        return 1;
      } else {
        return 0;
      }
    }

    if (dp[x][y][numMoves] != -1) {
      return dp[x][y][numMoves];
    }

    dp[x][y][numMoves] = 0;
    for (int i = 0; i < 16; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx && nx < bsize && 0 <= ny && ny < bsize) {
        dp[x][y][numMoves] += solve(nx, ny, numMoves - 1);
      }
    }
    return dp[x][y][numMoves];
  }

  ll howMany(int size, vector<int> start, vector<int> end, int numMoves) {
    for (int i = 0; i < 101; i++) {
      for (int j = 0; j < 101; j++) {
        for (int k = 0; k < 52; k++) {
          dp[i][j][k] = -1;
        }
      }
    }
    bsize = size;
    endpos.push_back(end[0]);
    endpos.push_back(end[1]);

    return solve(start[0], start[1], numMoves);
  }
};