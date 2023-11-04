#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, m, k;
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

  cin >> n >> m >> k;
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

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    used.assign(n + 1, false);
    if (try_kuhn(i))
      ans++;
  }

  for (int i = 1; i <= n; i++) {
    used.assign(n + 1, false);
    if (try_kuhn(i))
      ans++, k--;
    if (!k) break;
  }

  cout << ans;

  return 0;
}
