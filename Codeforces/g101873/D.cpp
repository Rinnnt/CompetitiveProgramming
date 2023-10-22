#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
typedef long long ll;

vector<int> edges[201];

map<string, int> names;

bool dfs(int a, int t) {
  if (a == t) {
    return true;
  }

  for (auto x : edges[a]) {
    if (dfs(x, t)) {
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  int nextfree = 0;
  for (int i = 0; i < n; i++) {
    string a, b, x;
    cin >> a >> x >> x >> x >> b;

    if (!names.count(a)) {
      names[a] = nextfree++;
    }
    if (!names.count(b)) {
      names[b] = nextfree++;
    }

    edges[names[a]].push_back(names[b]);
  }

  for (int i = 0; i < m; i++) {
    string a, b, x;
    cin >> a >> x >> x >> x >> b;

    string ans;
    if (!names.count(a) || !names.count(b)) {
      ans = "Pants on Fire";
    } else {
      if (dfs(names[a], names[b])) {
        ans = "Fact";
      } else if (dfs(names[b], names[a])) {
        ans = "Alternative Fact";
      } else {
        ans = "Pants on Fire";
      }
    }

    cout << ans << nl;
  }

}
