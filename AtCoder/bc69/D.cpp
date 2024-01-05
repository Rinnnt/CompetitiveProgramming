#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int h, w;
  cin >> h >> w;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int i = 0;
  int j = 0;
  int dj = 1;
  int c = 0;
  vector<vector<int>> b(h, vector<int>(w));
  while (i < h) {
    b[i][j] = c + 1;
    if (--a[c] == 0) c++;
    if (j + dj < 0 || j + dj >= w) {
      i++;
      dj *= -1;
    } else {
      j += dj;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << b[i][j] << " ";
    }
    cout << nl;
  }

  return 0;
}

