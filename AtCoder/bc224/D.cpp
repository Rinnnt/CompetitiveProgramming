#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[10];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  string s = "999999999";
  for (int i = 1; i <= 8; i++) {
    int p;
    cin >> p;
    s[p - 1] = i + '0';
  }

  queue<string> Q;
  Q.push(s);
  map<string, int> dist;
  dist[s] = 0;
  while (!Q.empty()) {
    string s = Q.front(); Q.pop();
    int v;
    for (int i = 1; i <= 9; i++) {
      if (s[i - 1] == '9') {
        v = i;
      }
    }

    for (auto x : edges[v]) {
      string t = s;
      swap(t[x - 1], t[v - 1]);
      if (dist.count(t)) continue;
      dist[t] = dist[s] + 1;
      Q.push(t);
    }
  }

  if (dist.count("123456789") == 0) cout << -1 << nl;
  else cout << dist["123456789"] << nl;


  return 0;
}

