#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int n, m;
int dp[1 << 12];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < (1 << 12); i++)
    dp[i] = 1e9;

  vector<pii> keys;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int x = 0;
    for (int j = 0; j < b; j++) {
      int c;
      cin >> c;
      c--;
      x |= (1 << c);
    }
    keys.push_back({a, x});
  }

  dp[0] = 0;
  for (auto key : keys) {
    for (int i = (1 << n) - 1; i >= 0; i--) {
      dp[i | key.second] = min(dp[i | key.second], dp[i] + key.first);
    }
  }

  cout << (dp[(1 << n) - 1] == 1e9 ? -1 : dp[(1 << n) - 1]) << nl;

  return 0;
}
