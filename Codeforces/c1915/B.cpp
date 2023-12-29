#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

char b[3][3];
char exists[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int x;

      for (int i = 0; i < 3; i++) {
        exists[i] = false;
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++) {
          b[i][j] = s[j];
          if (s[j] == '?') x = i;
        }
      }

      for (int i = 0; i < 3; i++) {
        if (b[x][i] != '?')
          exists[b[x][i] - 'A'] = true;
      }

      for (int i = 0; i < 3; i++) {
        if (!exists[i])
          cout << (char)('A' + i) << nl;
      }

    }

    return 0;
}
