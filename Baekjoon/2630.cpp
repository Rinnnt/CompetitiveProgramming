#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int N;
vector<vector<int>> paper;
int white = 0;
int blue = 0;

void count(int x, int y, int size) {
  bool same = true;
  for (int i = x; i < x + size; i++) {
    for (int j = y; j < y + size; j++) {
      if (paper[i][j] != paper[x][y]) {
        same = false;
        break;
      }
    }
    if (!same) {
      break;
    }
  }
  if (same) {
    if (paper[x][y]) {
      blue++;
    } else {
      white++;
    }
  } else {
    int half = size / 2;
    count(x, y, half);
    count(x + half, y, half);
    count(x, y + half, half);
    count(x + half, y + half, half);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    vector<int> v(N);
    for (int j = 0; j < N; j++) {
      cin >> v[j];
    }
    paper.push_back(v);
  }

  count(0, 0, N);
  cout << white << nl;
  cout << blue << nl;
}
