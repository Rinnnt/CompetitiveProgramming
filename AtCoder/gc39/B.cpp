#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int n;
int s[201][201];
int g[201][201];

bool bipartite() {
  vector<int> side(n, -1);

  bool is_bipartite = true;
  queue<int> q;
  for (int st = 0; st < n; st++) {
    if (side[st] == -1) {
      q.push(st);
      side[st] = 0;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u = 0; u < n; u++) {
          if (s[v][u]) {
            if (side[u] == -1) {
              side[u] = side[v] ^ 1;
              q.push(u);
            } else {
              is_bipartite &= side[u] != side[v];
            }
          }
        }
      }
    }
  }
  return is_bipartite;
}

int floyd_warshall() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        g[i][j] = 0;
      } else {
        if (s[i][j] == 1) {
          g[i][j] = 1;
        } else {
          g[i][j] = 1e9;
        }
      }
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  int maxdist = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      maxdist = max(g[i][j], maxdist);
    }
  }

  return maxdist;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < n; j++) {
      s[i][j] = str[j] - '0';
    }
  }

  if (!bipartite()) {
    cout << "-1" << nl;
  } else {
    cout << floyd_warshall() + 1 << nl;
  }

  return 0;
}

