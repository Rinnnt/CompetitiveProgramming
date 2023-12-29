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

  int n;
  cin >> n;

  vector<int> c(9);
  int mincost = n;
  for (int i = 0; i < 9; i++) {
    cin >> c[i];
    mincost = min(mincost, c[i]);
  }

  int length = n / mincost;

  vector<char> a(length);
  for (int i = 0; i < length; i++) {
    for (int j = 8; j >= 0; j--) {
      if ((ll)mincost * (length - 1 - i) + c[j] <= n) {
        n -= c[j];
        a[i] = '0' + j + 1;
        break;
      }
    }
  }

  for (auto c : a)
    cout << c;
  cout << nl;

  return 0;
}

