#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

vector<int> edges[100001];
int sz[100001];
int dist[100001];

int dfs(int cur, int p, int d) {
  sz[cur] = 1;
  dist[cur] = d;
  for (auto x : edges[cur])
    if (x != p)
      sz[cur] += dfs(x, cur, d + 1);
  return sz[cur];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  dfs(1, -1, 0);

  int cur = n;
  int prev = -1;
  int d = dist[n];
  int fnodes = d / 2;
  int snodes = (d - 1) / 2;

  int f = 0;
  int s = 0;

  for (int i = 0; i <= snodes; i++) {
    int next = -1;
    for (auto x : edges[cur]) {
      if (x != prev && dist[x] > dist[cur])
        s += sz[x];
      if (dist[x] + 1 == dist[cur])
        next = x;
    }
    s++;
    prev = cur;
    cur = next;
  }

  for (int i = 0; i <= fnodes; i++) {
    int next = -1;
    for (auto x : edges[cur]) {
      if (x != prev && dist[x] > dist[cur])
        f += sz[x];
      if (dist[x] + 1 == dist[cur])
        next = x;
    }
    f++;
    prev = cur;
    cur = next;
  }

  f--;
  s--;

  if (f > s)
    cout << "Fennec" << nl;
  else
    cout << "Snuke" << nl;

  return 0;
}

