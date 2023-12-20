#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

bool prime[2000001];
bool used[1000001] = {};
int a[1001][1001] = {};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 2000001; i++)
    prime[i] = true;
  prime[1] = false;

  for (int i = 2; i * i <= 2000001; i++)
    if (prime[i])
      for (int j = i + i; j < 2000001; j += i)
        prime[j] = false;

  int n;
  cin >> n;

  if (n % 2) {
    a[n / 2][n / 2] = 7;
    a[n / 2][n / 2 + 1] = 8;
    a[n / 2 + 1][n / 2] = 2;
    a[n / 2 - 1][n / 2 + 1] = 1;
    used[1] = true;
    used[2] = true;
    used[7] = true;
    used[8] = true;

    vector<pair<int, int>> ps;
    for (int i = 1; i <= n * n; i += 2) {
      for (int j = 2; j < n * n; j += 2) {
        if (!used[i] && !used[j] && !prime[i + j]) {
          used[i] = used[j] = true;
          ps.push_back({i, j});
          break;
        }
      }
      if (ps.size() == 2 * (n / 2) - 1) break;
    }

    for (int i = 0; i < n / 2; i++) {
      a[n / 2][i] = ps[i].first;
      a[n / 2 + 1][i] = ps[i].second;
    }

    for (int i = n / 2 + 2; i < n; i++) {
      a[n / 2 - 1][i] = ps[i - 2].first;
      a[n / 2][i] = ps[i - 2].second;
    }
  } else {
    vector<pair<int, int>> ps;
    for (int i = 1; i <= n * n; i += 2) {
      for (int j = 2; j < n * n; j += 2) {
        if (!used[i] && !used[j] && !prime[i + j]) {
          used[i] = used[j] = true;
          ps.push_back({i, j});
          break;
        }
      }
      if (ps.size() == n) break;
    }

    for (int i = 0; i < n; i++) {
      a[n / 2 - 1][i] = ps[i].first;
      a[n / 2][i] = ps[i].second;
    }
  }

  int r = 0;
  int c = 0;
  for (int i = 1; i <= n * n; i += 2) {
    if (!used[i]) {
      a[r][c] = i;
      while (a[r][c] != 0) {
        if (++c == n) r++, c = 0;
      }
    }
  }

  for (int i = 2; i <= n * n; i += 2) {
    if (!used[i]) {
      a[r][c] = i;
      while (a[r][c] != 0) {
        if (++c == n) r++, c = 0;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << nl;
  }

  return 0;
}

