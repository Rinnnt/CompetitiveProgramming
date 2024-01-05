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

  int L;
  cin >> L;
  int cc = 0;
  vector<pii> e;
  for (int i = 18; i >= 0; i--) {
    while (L >= cc + (1 << i)) {
      e.push_back({19 - i, cc});
      cc += (1 << i);
    }
  }

  cout << 20 << " " << e.size() + 36 << nl;
  for (int i = 1; i < 19; i++) {
    cout << i + 1 << " " << i + 2 << " " << 0 << nl;
    cout << i + 1 << " " << i + 2 << " " << (1 << (18 - i)) << nl;
  }
  for (int i = 0; i < e.size(); i++ ){
    cout << 1 << " " << e[i].first + 1 << " " << e[i].second << nl;
  }

  return 0;
}

