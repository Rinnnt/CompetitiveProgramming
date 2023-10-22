#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'
#define MAXN 201

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

  for (int i = 1; i <= n; i++) {
    make_set(i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int d;
      cin >> d;
      if (d) {
        union_set(i, j);
      }
    }
  }

  bool possible = true;
  int f;
  cin >> f;
  int g = find_set(f);
  for (int i = 1; i < m; i++) {
    int x;
    cin >> x;
    if (g != find_set(x)) {
      possible = false;
    }
  }

  if (possible) {
    cout << "YES" << nl;
  } else {
    cout << "NO" << nl;
  }

  return 0;
}
