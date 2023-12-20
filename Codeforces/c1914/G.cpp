#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

#define MAXN 1005

const ll mod = 998244353;

int parent[MAXN];
int setsize[MAXN];

void make_set(int v) {
  parent[v] = v;
  setsize[v] = 1;
}

int find_set(int v) {
  if (v == parent[v]) {
    return v;
  }
  return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (setsize[a] < setsize[b]) {
      swap(a, b);
    }
    parent[b] = a;
    setsize[a] += setsize[b];
  }
}

int li[MAXN];
int ri[MAXN];
int set_starts[MAXN];

vector<int> edges[MAXN];
int visited[MAXN];

int dfs(int cur) {
  visited[cur] = true;
  int ans = 1;
  for (auto x : edges[cur]) {
    if (!visited[x]) {
      ans += dfs(x);
    }
  }
  return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      for (int i = 0; i < MAXN; i++) {
        li[i] = ri[i] = -1;
        set_starts[i] = 0;
        edges[i].clear();
      }

      int n;
      cin >> n;

      for (int i = 0; i < 2 * n; i++) {
        int c;
        cin >> c;
        if (li[c] == -1) li[c] = i;
        else ri[c] = i;
      }

      for (int i = 1; i <= n; i++)
        make_set(i);

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (i == j) continue;
          if (li[i] > ri[j] || ri[i] < li[j]) continue;
          union_set(i, j);

          if ((li[i] < li[j] && li[j] < ri[i]) || (li[i] < ri[j] && ri[j] < ri[i])) {
            edges[i].push_back(j);
          }
        }
      }

      set<int> sets;
      for (int i = 1; i <= n; i++) {
        sets.insert(find_set(i));
        for (int j = 0; j < MAXN; j++)
          visited[j] = false;
        if (dfs(i) == setsize[find_set(i)]) {
          set_starts[find_set(i)] += 2;
        }
      }

      ll num_sets = 1;
      for (int i = 1; i <= n; i++) {
        if (i == find_set(i)) {
          num_sets *= set_starts[i];
          num_sets %= mod;
        }
      }

      cout << sets.size() << ' ' << num_sets << nl;
    }

    return 0;
}
