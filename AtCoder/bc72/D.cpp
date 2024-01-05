#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<int> p(n + 1, 0);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    if (p[i] == i + 1) {
      cnt++;
      swap(p[i], p[i + 1]);
    }
  }

  cout << cnt << nl;

  return 0;
}

