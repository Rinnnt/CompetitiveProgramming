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
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      edges[i].push_back(x);
    }
  }

  mt.assign(m + 1, -1);

  int ret = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      used.assign(2 * n + 1, false);
      if (try_kuhn(i)) {
        ret++;
      }
    }
  }

  cout << ret;

  return 0;
}
