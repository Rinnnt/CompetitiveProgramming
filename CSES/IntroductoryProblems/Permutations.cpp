#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    if (n == 1) {
      cout << "1";
      return 0;
    }
    if (n == 4) {
      cout << "2 4 1 3";
      return 0;
    }
    if (n < 5) {
      cout << "NO SOLUTION";
    } else {
      for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
      }
      for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
      }
    }

    return 0;
}