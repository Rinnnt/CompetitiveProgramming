#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll total = (n * (n + 1)) / 2;
    if (total % 2 == 1) {
      cout << "NO";
    } else {
      cout << "YES" << nl;

      ll half = total / 2;
      ll largest = n;
      ll sum = 0;
      while (half - sum >= largest) {
        sum += largest--;
      }
      ll nums = n - largest + (half - sum != 0 ? 1 : 0);
      cout << nums << nl;
      if (half - sum != 0) {
        cout << half - sum << " ";
      }
      for (int i = largest + 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << nl << n - nums << nl;
      for (int i = 1; i <= largest; i++) {
        if (i != half - sum) {
          cout << i << " ";
        }
      }
      
    }

    return 0;
}