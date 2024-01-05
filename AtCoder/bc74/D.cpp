#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int dist[301][301];
bool composed[301][301];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dist[i][j];
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == k || j == k) continue;
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          cout << -1 << nl;
          return 0;
        }
        if (dist[i][j] == dist[i][k] + dist[k][j]) {
          composed[i][j] = true;
          composed[j][i] = true;
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!composed[i][j])
        ans += dist[i][j];
    }
  }

  cout << ans / 2 << nl;

  return 0;
}

