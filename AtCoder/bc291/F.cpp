#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[100001];
vector<int> redges[100001];
int dist[100001];
int rdist[100001];
string mv[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    dist[i] = 1e9;
    rdist[i] = 1e9;
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') {
        edges[i].push_back(i + j + 1);
        redges[i + j + 1].push_back(i);
      }
    }
    mv[i] = s;
  }

  deque<int> q;
  q.push_back(1);
  dist[1] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    for (auto x : edges[cur]) {
      if (dist[x] > dist[cur] + 1) {
        dist[x] = dist[cur] + 1;
        q.push_back(x);
      }
    }
  }

  q.push_back(n);
  rdist[n] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    for (auto x : redges[cur]) {
      if (rdist[x] > rdist[cur] + 1) {
        rdist[x] = rdist[cur] + 1;
        q.push_back(x);
      }
    }
  }

  for (int i = 2; i < n; i++) {
    int mn = 1e9;
    for (int j = max(i - m + 1, 1); j < i; j++) {
      for (int k = i + 1; k <= min(n, j + m); k++) {
        if (mv[j][k - j - 1] == '1') {
          mn = min(mn, dist[j] + rdist[k] + 1);
        }
      }
    }
    cout << (mn == 1e9 ? -1 : mn) << " ";
  }
  cout << nl;

  return 0;
}

