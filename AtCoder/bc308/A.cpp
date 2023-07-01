#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool yes = true;
    vector<int> a(8);
    for (int i = 0; i < 8; i++) {
      cin >> a[i];
      if (!(a[i] >= 100 && a[i] <= 675)) {
        yes = false;
      }
      if (a[i] % 25 != 0) {
        yes = false;
      }
    }

    for (int i = 0; i < 7; i++) {
      if (a[i] > a[i + 1]) {
        yes = false;
      }
    }
    if (yes) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    return 0;
}
