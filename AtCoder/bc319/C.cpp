#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int a[3][3];
bool seen[3][3];
int seenall = 0;

bool disappoint() {
  for (int i = 0; i < 3; i++) {
    if (seen[i][0] && seen[i][1] && !seen[i][2] && a[i][0] == a[i][1]) {
      return true;
    }
    if (seen[i][1] && seen[i][2] && !seen[i][0] && a[i][1] == a[i][2]) {
      return true;
    }
    if (seen[i][0] && seen[i][2] && !seen[i][1] && a[i][0] == a[i][2]) {
      return true;
    }
  }
  for (int j = 0; j < 3; j++) {
    if (seen[0][j] && seen[1][j] && !seen[2][j] && a[0][j] == a[1][j]) {
      return true;
    }
    if (seen[1][j] && seen[2][j] && !seen[0][j] && a[1][j] == a[2][j]) {
      return true;
    }
    if (seen[0][j] && seen[2][j] && !seen[1][j] && a[0][j] == a[2][j]) {
      return true;
    }
  }
  if (seen[0][0] && seen[1][1] && !seen[2][2] && a[0][0] == a[1][1]) {
    return true;
  }
  if (seen[1][1] && seen[2][2] && !seen[0][0] && a[1][1] == a[2][2]) {
    return true;
  }
  if (seen[0][0] && seen[2][2] && !seen[1][1] && a[0][0] == a[2][2]) {
    return true;
  }
  if (seen[0][2] && seen[1][1] && !seen[2][0] && a[0][2] == a[1][1]) {
    return true;
  }
  if (seen[2][0] && seen[1][1] && !seen[0][2] && a[2][0] == a[1][1]) {
    return true;
  }
  if (seen[0][2] && seen[2][0] && !seen[1][1] && a[0][2] == a[2][0]) {
    return true;
  }
  return false;
}

void dfs(int x) {
  if (x == 9) {
    seenall++;
    return;
  }
  if (disappoint()) {
    return;
  }
  for (int i = 0; i < 3; i++){ 
    for (int j = 0; j < 3; j++) {
      if (!seen[i][j]) {
        seen[i][j] = true;
        dfs(x + 1);
        seen[i][j] = false;
      }
    }
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(14);

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> a[i][j];
      }
    }

    dfs(0);

    cout << ((double)seenall) / (9 * 8 * 7 * 6 * 5 * 4 * 3 * 2);


    return 0;
}
