#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int n, k;
int w[2000][2000];
int b[2000][2000];
int whites[2001][2001];
int blacks[2001][2001];

int clamp(int x) {
  return min(2 * k, max(0, x));
}

int whites_in_range(int i, int j) {
  return whites[clamp(i)][clamp(j)]
    - whites[clamp(i - k)][clamp(j)]
    - whites[clamp(i)][clamp(j - k)]
    + whites[clamp(i - k)][clamp(j - k)];
}

int blacks_in_range(int i, int j) {
  return blacks[clamp(i)][clamp(j)]
    - blacks[clamp(i - k)][clamp(j)]
    - blacks[clamp(i)][clamp(j - k)]
    + blacks[clamp(i - k)][clamp(j - k)];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x %= 2 * k;
    y %= 2 * k;
    char c;
    cin >> c;
    if (c == 'W') w[y][x]++;
    if (c == 'B') b[y][x]++;
  }

  for (int i = 0; i < 2 * k; i++) {
    int ws = 0;
    int bs = 0;
    for (int j = 0; j < 2 * k; j++) {
      ws += w[i][j];
      bs += b[i][j];
      whites[i + 1][j + 1] = whites[i][j + 1] + ws;
      blacks[i + 1][j + 1] = blacks[i][j + 1] + bs;
    }
  }

  int satisfied = 0;
  for (int i = 0; i < 2 * k; i++) {
    for (int j = 0; j < 2 * k; j++) {
      int cur_satisfied = 0;
      cur_satisfied += whites_in_range(i, j);
      cur_satisfied += whites_in_range(i + 2 * k, j);
      cur_satisfied += whites_in_range(i, j + 2 * k);
      cur_satisfied += whites_in_range(i + 2 * k, j + 2 * k);
      cur_satisfied += whites_in_range(i + k, j + k);
      cur_satisfied += whites_in_range(i + k, j - k);
      cur_satisfied += blacks_in_range(i + k, j);
      cur_satisfied += blacks_in_range(i + k, j + 2 * k);
      cur_satisfied += blacks_in_range(i, j + k);
      cur_satisfied += blacks_in_range(i + 2 * k, j + k);
      cur_satisfied += blacks_in_range(i, j - k);
      cur_satisfied += blacks_in_range(i + 2 * k, j - k);
      satisfied = max(satisfied, cur_satisfied);
    }
  }

  cout << satisfied << nl;

  return 0;
}

