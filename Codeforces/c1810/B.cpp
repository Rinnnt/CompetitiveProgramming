#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll n;
      cin >> n;

      if (n % 2 == 0) {
        cout << "-1" << nl;
        continue;
      }

      vector<int> turns;
      while (n != 1) {
        int p1 = (n + 1) / 2;
        int p2 = (n - 1) / 2;
        if (p1 % 2 == 1) {
          n = p1;
          turns.push_back(1);
        } else {
          n = p2;
          turns.push_back(2);
        }
      }

      cout << turns.size() << nl;
      for (int i = turns.size() - 1; i >= 0; i--) {
        cout << turns[i] << " ";
      }
      cout << nl;
    }

    return 0;
}
