#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int n, a[14];
int L[2600001];

void dfs(int x, int s) {
  if (x == n) {
    if (s >= 1) {
      L[s] = 1;
    }
  } else {
    dfs(x + 1, s);
    dfs(x + 1, s + a[x]);
    dfs(x + 1, s - a[x]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  dfs(0, 0);

  int ans = 0;
  for (int i = 1; i <= sum; i++) {
    if (!L[i]) {
      ans++;
    }
  }

  cout << ans;

  return 0;
}
