#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int n, m;
bool visited[101];
vector<int> edges[101];

bool dfs(int cur, int prev) {
  visited[cur] = true;

  if (cur == n) {
    string s;
    cin >> s;
    return true;
  }

  int k;
  cin >> k;
  if ( k == -1) return true;
  for (int i = 0; i < k; i++) {
    int v;
    cin >> v;
    edges[cur].push_back(v);
  }

  for (auto v : edges[cur]) {
    if (!visited[v]) {
      cout << v << nl;
      if (dfs(v, cur)) return true;

      int k;
      cin >> k;
      for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
      }
    }
  }

  cout << prev << nl;
  return false;
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0); cout.tie(0);

  cin >> n >> m;

  dfs(1, -1);

  return 0;
}

