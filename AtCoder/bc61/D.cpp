#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

struct edge {
  ll a;
  ll b;
  ll c;

  edge(ll _a, ll _b, ll _c) {
    a = _a;
    b = _b;
    c = _c;
  }
};

const ll INF = 1e15;

vector<edge> edges;
ll d[1001];
bool neg[1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    edges.push_back(edge(a, b, -c));
  }

  for (int i = 0; i < 1001; i++) {
    d[i] = INF;
    neg[i] = false;
  }
  d[1] = 0;

  // bellman ford
  for (int i = 0; i < n - 1; i++)
    for (edge e : edges)
      if (d[e.a] < INF)
        d[e.b] = min(d[e.b], d[e.a] + e.c);

  // bellman ford to find nodes reachable from
  // a neg cycle
  for (int i = 0; i < n; i++)
    for (edge e : edges)
      if (d[e.a] < INF) {
        if (d[e.b] > d[e.a] + e.c)
          neg[e.b] = true;
        if (neg[e.a])
          neg[e.b] = true;
      }

  if (neg[n])
    cout << "inf" << nl;
  else
    cout << -d[n] << nl;

  return 0;
}

