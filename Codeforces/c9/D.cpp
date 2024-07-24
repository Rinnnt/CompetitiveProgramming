#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

ll bst_cnt[36];
ll memo[36][36];

ll solve(int n, int h) {
  if (n == 0) return h <= 0;
  if (h <= 1) return bst_cnt[n];

  if (memo[n][h] != -1LL) return memo[n][h];

  ll res = 0;
  for (int l = 0; l < n; l++) {
    res += bst_cnt[l] * solve(n - l - 1, h - 1);
    res += solve(l, h - 1) * bst_cnt[n - l - 1];
    res -= solve(l, h - 1) * solve(n - l - 1, h - 1);
  }

  return memo[n][h] = res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 36; i++)
    for (int j = 0; j < 36; j++)
      memo[i][j] = -1LL;

  bst_cnt[0] = 1;
  for (int i = 1; i < 36; i++)
    for (int l = 0; l < i; l++)
      bst_cnt[i] += bst_cnt[l] * bst_cnt[i - l - 1];

  int n, h;
  cin >> n >> h;
  cout << solve(n, h) << nl;

  return 0;
}
