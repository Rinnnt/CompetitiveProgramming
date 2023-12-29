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

  ll n, d;
  cin >> n >> d;

  if (n * d <= (n * (n - 1)) / 2) {
    cout << "Yes" << nl;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= d; j++) {
        cout << i + 1 << " " << (i + j) % n + 1 << nl;
      }
    }
  } else {
    cout << "No" << nl;
  }

  return 0;
}

