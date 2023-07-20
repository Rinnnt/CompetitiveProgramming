#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "1\n1" << nl;
  } else if (m == 1) {
    cout << "2" << nl;
    for (int j = 0; j < n; j++) {
      cout << (j % 2 ? 2 : 1) << nl;
    }
  } else if (n == 1) {
    cout << "2" << nl;
    for (int j = 0; j < m; j++) {
      cout << (j % 2 ? 2 : 1) << " ";
    }
  } else {
    cout << "4" << nl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << (i % 2 ? 3 : 1) + (j % 2) << " ";
      }
      cout << nl;
    }
  }


  return 0;
}
