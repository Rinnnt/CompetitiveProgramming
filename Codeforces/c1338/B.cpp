#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[100001];
int dist[100001] = {};
vector<int> lds;
int same_parent_leaves = 0;
bool has_leaf[100001] = {};

void dfs(int c, int p) {
  dist[c] = dist[p] + 1;

  for (auto n : edges[c])
    if (n != p)
      dfs(n, c);

  if (edges[c].size() == 1) {
    lds.push_back(dist[c]);

    if (has_leaf[edges[c][0]]) {
      same_parent_leaves++;
    } else {
      has_leaf[edges[c][0]] = true;
    }
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }

    dist[0] = -1;
    dfs(1, 0);

    sort(lds.begin(), lds.end());

    /*
    for (auto ld : lds) cout << ld << " ";
    cout << nl;
    */
    bool oddlen = false;
    for (int i = 1; i < lds.size(); i++)
      if ((lds[i] - lds[i - 1]) % 2)
        oddlen = true;
    if (edges[1].size() == 1)
      for (int i = 0; i < lds.size(); i++)
        if (lds[i] % 2)
          oddlen = true;

    cout << (oddlen ? 3 : 1) << " " << n - 1 - same_parent_leaves << nl;

    return 0;
}
