#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'

int rows, cols;
int killer[300][300][300] = {0};
bool m[300][300];

bool is_killer(int i, int j, int k) {
  if (killer[i][j][k] > 0) return true;
  if (killer[i][j][k] < 0) return false;

  if (!is_killer(i + 1, j + 1, k - 2)) return (killer[i][j][k] = false);
  for (int ii = 0; ii < k; ii++)
    if (m[i + ii][j] != m[i + k - 1 - ii][j + k - 1]) return (killer[i][j][k] = false);
  for (int jj = 0; jj < k; jj++)
    if (m[i][j + jj] != m[i + k - 1][j + k - 1 - jj]) return (killer[i][j][k] = false);
  return (killer[i][j][k] = true);
}

bool has_killer(int k) {
  for (int i = 0; i < rows - (k - 1); i++) {
    for (int j = 0; j < cols - (k - 1); j++) {
      if (is_killer(i, j, k)) return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> rows >> cols;

  for (int i = 0; i < rows; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < cols; j++) {
      m[i][j] = s[j] == '1';
      killer[i][j][1] = true;
    }
  }

  for (int i = 0; i < rows - 1; i++)
    for (int j = 0; j < cols - 1; j++)
      killer[i][j][2] = (m[i][j] == m[i + 1][j + 1] && m[i][j + 1] == m[i + 1][j]) ? 1 : -1;

  int ans = 1;

  // evens (2k)
  int l = 0, r = min(rows, cols) / 2 + 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int k = 2 * mid;
    if (has_killer(k))
      l = mid;
    else
      r = mid;
  }
  ans = max(ans, 2 * l);

  // odds (2k - 1)
  l = 0, r = (min(rows, cols) + 1) / 2 + 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int k = 2 * mid - 1;
    if (has_killer(k))
      l = mid;
    else
      r = mid;
  }
  ans = max(ans, 2 * l - 1);

  // 1 2 3 4 5 6 7
  // l = 0  2   4   6 r = 8
  // l = 0  1   2   3     4
  // l = -1 1 3 5 7 r = 9
  // l = 0 1 2 3 4   5

  // 1 2 3 4 5 6 7 8
  // l = 0 2 4 6 8 r = 10
  // l = 0 1 2 3 4      5
  // l = -1 1 3 5 7 r = 9
  // l = 0  1 2 3 4     5

  cout << ans << nl;


  return 0;
}
