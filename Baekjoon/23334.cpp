#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int mg = -1;
    int ms = -1;
    int mb = -1;
    string mc;
    for (int i = 0; i < n; i++) {
      int g, s, b;
      cin >> g  >> s >> b;
      string c;
      getline(cin, c);

      if (g > mg || (g == mg && s > ms) || (g == mg && s == ms && b > mb)) {
        mg = g;
        ms = s;
        mb = b;
        mc = c;
      }
    }

    cout << mc.substr(1);

    return 0;
}
