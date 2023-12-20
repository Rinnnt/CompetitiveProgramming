#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int x[100001];
vector<int> edges[100001];
vector<int> tops[100001];

void dfs(int cur, int p) {
  vector<int> nums(1, x[cur]);
  for (auto x : edges[cur]) {
    if (x != p) {
      dfs(x, cur);
      for (auto a : tops[x])
        nums.push_back(a);
    }
  }

  sort(nums.rbegin(), nums.rend());

  for (int i = 0; i < min(20, (int)nums.size()); i++)
    tops[cur].push_back(nums[i]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> x[i];

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(1, -1);

  for (int i = 0; i < q; i++) {
    int v, k;
    cin >> v >> k;
    cout << tops[v][k - 1] << nl;
  }


  return 0;
}

