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

  int n, w, h;
  cin >> n >> w >> h;

  while (n--) {
    int k;
    cin >> k;
    if (k * k <= w * w + h * h)
      cout << "DA" << nl;
    else
      cout << "NE" << nl;
  }

  return 0;
}

