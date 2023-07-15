#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n;
int cnt = 0;
bool cols[15];
bool diags[29];
bool rdiags[29];

void solve(int idx) {
  if (idx == n) {
    cnt++;
    return;
  }
  int x = idx;
  for (int y = 0; y < n; y++) {
    if (cols[y] && diags[x + y] && rdiags[x - y + n - 1]) {
      cols[y] = false;
      diags[x + y] = false;
      rdiags[x - y + n - 1] = false;

      solve(idx + 1);

      cols[y] = true;
      diags[x + y] = true;
      rdiags[x - y + n - 1] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for (int i = 0; i < 15; i++) {
    cols[i] = true;
  }
  for (int i = 0; i < 29; i++) {
    diags[i] = true;
    rdiags[i] = true;
  }

  solve(0);

  cout << cnt;

  return 0;
}
