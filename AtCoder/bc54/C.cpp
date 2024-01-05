#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

bool edge[9][9];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edge[u][v] = true;
    edge[v][u] = true;
  }

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }

  int cnt = 0;
  do {
    bool valid = a[0] == 1;
    if (valid) {
      for (int i = 1; i < n; i++) {
        if (!edge[a[i]][a[i - 1]]) {
          valid = false;
          break;
        }
      }
    }

    if (valid)
      cnt += 1;

  } while (next_permutation(a.begin(), a.end()));

  cout << cnt << nl;

  return 0;
}

