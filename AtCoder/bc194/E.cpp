#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> pos(n + 1, vector<int>(1, 0));

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x].push_back(i);
  }

  for (int i = 0; i < n + 1; i++) {
    pos[i].push_back(n + 1);
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < pos[i].size() - 1; j++) {
      if (pos[i][j + 1] - pos[i][j] > m) {
        cout << i << nl;
        return 0;
      }
    }
  }

  return 0;
}

