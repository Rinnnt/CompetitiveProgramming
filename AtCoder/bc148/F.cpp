#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[100001];
int tdist[100001];
int adist[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, t, a;
  cin >> n >> t >> a;

  for (int i = 1; i <= n; i++) {
    tdist[i] = 1e9;
    adist[i] = 1e9;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  deque<int> q;
  q.push_back(t);
  tdist[t] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();
    for (auto x : edges[cur]) {
      if (tdist[x] > tdist[cur]  + 1) {
        tdist[x] = tdist[cur] + 1;
        q.push_back(x);
      }
    }
  }

  q.push_back(a);
  adist[a] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();
    for (auto x : edges[cur]) {
      if (adist[x] > adist[cur]  + 1) {
        adist[x] = adist[cur] + 1;
        q.push_back(x);
      }
    }
  }

  int moves = 0;
  for (int i = 1; i <= n; i++) {
    if (tdist[i] < adist[i]) {
      moves = max(moves, adist[i] - 1);
    }
  }
  cout << moves << nl;

  return 0;
}

