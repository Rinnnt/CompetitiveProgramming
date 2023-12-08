#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

char winner = '.';
char b[30][30];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < n - 2; j++)
      if (b[i][j] != '.')
        if (b[i][j] == b[i + 1][j + 1] && b[i][j] == b[i + 2][j + 2])
          winner = b[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 2; j++)
      if (b[i][j] != '.')
        if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2])
          winner = b[i][j];

  for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < n; j++)
      if (b[i][j] != '.')
        if (b[i][j] == b[i + 1][j] && b[i][j] == b[i + 2][j])
          winner = b[i][j];

  for (int i = 0; i < n - 2; i++)
    for (int j = 2; j < n; j++)
      if (b[i][j] != '.')
        if (b[i][j] == b[i + 1][j - 1] && b[i][j] == b[i + 2][j - 2])
          winner = b[i][j];

  if (winner == '.')
    cout << "ongoing" << nl;
  else
    cout << winner << nl;

  return 0;
}
