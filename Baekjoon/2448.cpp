#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool b[3072][6143];
int width[11];

void draw(int n, int x, int y) {
  if (n == 3) {
    b[x - 2][y + 2] = true;
    b[x - 1][y + 1] = true;
    b[x - 1][y + 3] = true;
    b[x][y] = true;
    b[x][y + 1] = true;
    b[x][y + 2] = true;
    b[x][y + 3] = true;
    b[x][y + 4] = true;
  } else {
    draw(n / 2, x, y);
    draw(n / 2, x - n / 2, y + n / 2);
    draw(n / 2, x, y + n);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  width[0] = 5;
  for (int i = 0; i < 10; i++) {
    width[i + 1] = 2 * width[i] + 1;
  }

  draw(n, 3071, 0);

  for (int x = 3072 - n; x < 3072; x++) {
    for (int y = 0; y < width[(int)log2(n / 3)]; y++) {
      cout << (b[x][y] ? '*' : ' ');
    }
    cout << nl;
  }

  return 0;
}
