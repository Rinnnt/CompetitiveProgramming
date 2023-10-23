#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, m;
vector<vector<int>> edges;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
  if (used[v]) {
    return false;
  }
  used[v] = true;
  for (auto x : edges[v]) {
    if (mt[x] == -1 || try_kuhn(mt[x])) {
      mt[x] = v;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  edges.assign(n + 1, vector<int>());
  mt.assign(m + 1, -1);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      edges[i].push_back(x);
    }
  }

  for (int i = 1; i <= n; i++) {
    used.assign(n + 1, false);
    try_kuhn(i);
  }

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (mt[i] != -1) {
      ans += 1;
    }
  }

  cout << ans;

  return 0;
}
