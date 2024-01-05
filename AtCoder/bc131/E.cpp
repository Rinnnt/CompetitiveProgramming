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

  int n, k;
  cin >> n>> k;

  if (k > ((n - 1) * (n - 2)) / 2) {
    cout << -1 << nl;
  } else {
    vector<pii> edges;
    int ck = ((n - 1) * (n - 2)) / 2;
    for (int i = 2; i <= n; i++)
      edges.push_back({1, i});

    int i = 2;
    int j = 3;
    while (ck > k) {
      edges.push_back({i, j});
      j++;
      if (j > n) {
        i++;
        j = i + 1;
      }
      ck--;
    }

    cout << edges.size() << nl;
    for (auto x : edges)
      cout << x.first << " " << x.second << nl;
  }


  return 0;
}

