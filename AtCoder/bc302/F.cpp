#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

vector<int> edges[400001];
int dist[400001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 400001; i++)
    dist[i] = 1e9;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      int s;
      cin >> s;
      edges[i].push_back(s + n);
      edges[s + n].push_back(i);
    }
  }

  deque<int> q;
  q.push_back(n + 1);
  dist[n + 1] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    for (auto v : edges[cur]) {
      if (dist[v] > dist[cur] + 1) {
        dist[v] = dist[cur] + 1;
        q.push_back(v);
      }
    }
  }

  cout << (dist[n + m] == 1e9 ? -1 : (dist[n + m] - 2) / 2) << nl;

  return 0;
}
