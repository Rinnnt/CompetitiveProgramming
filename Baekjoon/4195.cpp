#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'
#define MAXN 200050

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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n + 10; i++) {
      make_set(i);
    }

    int nextfree = 0;
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
      string a, b;
      cin >> a >> b;
      if (!mp.count(a)) {
        mp[a] = nextfree++;
      }
      if (!mp.count(b)) {
        mp[b] = nextfree++;
      }

      union_set(mp[a], mp[b]);
      cout << sz[find_set(mp[a])] << nl;
    }
  }

  return 0;
}
