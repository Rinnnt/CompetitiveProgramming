#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll n, s, e, t;
const ll mod = 1000003;

ll graph[60][60] = {0};
ll ans[60][60] = {0};

void matmul(ll (&a)[60][60], ll (&b)[60][60], ll (&c)[60][60]) {
  ll res[60][60] = {0};
  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < 60; j++) {
      for (int k = 0; k < 60; k++ ) {
        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
      }
    }
  }

  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < 60; j++) {
      c[i][j] = res[i][j] % mod;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> s >> e >> t;

  for (int i = 0; i < 60; i++) {
      ans[i][i] = 1;
  }

  for (int i = 1; i <= 10; i++) {
    for (int j = 0; j < 4; j++) {
      graph[5 * i + j + 1][5 * i + j] = 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char w;
      cin >> w;
      w -= '0';
      if (w != 0) {
        graph[5 * i][5 * j + w - 1] = 1;
      }
    }
  }

  while (t) {
    if (t & 1) {
      matmul(graph, ans, ans);
    }
    matmul(graph, graph, graph);
    t >>= 1;
  }

  cout << ans[5 * s][5 * e] << nl;

  return 0;
}

