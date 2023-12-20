#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 998244353;

vector<int> d[5001];
ll t[5001][5002];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    d[u].push_back(v);
    d[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
    t[0][i] = 0;
  t[0][1] = 1;
  t[0][5001] = 1;

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      t[i][j] = t[i - 1][5001] - t[i - 1][j];
      for (auto x : d[j])
        t[i][j] = (t[i][j] - t[i - 1][x]) % mod;
      t[i][5001] = (t[i][5001] + t[i][j]) % mod;
    }
  }

  cout << (t[k][1] + mod) % mod << nl;

  return 0;
}

