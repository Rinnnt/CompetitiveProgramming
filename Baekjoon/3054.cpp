#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'

char b[5][61];

void set_frame(int i, char c) {
    b[0][2 + 4 * i] = c;
    b[1][1 + 4 * i] = c;
    b[1][3 + 4 * i] = c;
    b[2][0 + 4 * i] = c;
    b[2][4 + 4 * i] = c;
    b[3][1 + 4 * i] = c;
    b[3][3 + 4 * i] = c;
    b[4][2 + 4 * i] = c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 61; j++)
      b[i][j] = '.';

  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    b[2][2 + 4 * i] = s[i];
    set_frame(i, '#');
  }

  for (int i = 2; i < s.size(); i += 3)
    set_frame(i, '*');

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 1 + 4 * s.size(); j++) {
      cout << b[i][j];
    }
    cout << nl;
  }



  return 0;
}
