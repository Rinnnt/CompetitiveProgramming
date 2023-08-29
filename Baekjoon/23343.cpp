#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string x, y;
    cin >> x >> y;

    bool xnan = false;
    for (auto c : x) {
      if (!isdigit(c)) {
        xnan = true;
      }
    }
    
    bool ynan = false;
    for (auto c : y) {
      if (!isdigit(c)) {
        ynan = true;
      }
    }

    if (xnan || ynan) {
      cout << "NaN" << nl;
    } else {
      int xv = atoi(x.c_str());
      int yv = stoi(y);
      cout << xv - yv << nl;
    }

    return 0;
}
