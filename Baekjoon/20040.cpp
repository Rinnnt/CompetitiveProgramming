#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'
#define MAXN 500001

int p[MAXN];
int sz[MAXN];

void make_set(int v) {
  p[v] = v;
  sz[v] = 1;
}

int find_set(int v) {
  if (v == p[v]) {
    return v;
  }
  return p[v] = find_set(p[v]);
}

void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    p[b] = a;
    sz[a] += sz[b];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    make_set(i);
  }

  int ans = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (ans == 0 && find_set(a) == find_set(b)) {
      ans = i + 1;
    }
    union_set(a, b);
  }

  cout << ans << nl;

  return 0;
}
