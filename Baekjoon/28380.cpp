#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

char sequence[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int si = 0;
    int level = 0;
    bool check = false;
    bool possible = false;
    int b = 0;
    int x = 0;
    for (auto c : s) {
      if (c == '(') {
        level += 1;
        if (check) {
          if (sequence[si++] != c) {
            possible = true;
          }
        } else {
          sequence[si++] = c;
        }
      } else {
        level -= 1;
        if (check) {
          if (sequence[si++] != c) {
            possible = true;
          }
          if (level == 0) {
            if (possible) {
              break;
            }
            si = 0;
          }
        } else {
          sequence[si++] = c;
          if (level == 0) {
            check = true;
            si = 0;
            x = b + 1;
          }
        }
      }
      b++;
    }

    if (possible) {
      for (int i = x; i < s.size(); i++) {
        cout << s[i];
      }
      for (int i = 0; i < x; i++) {
        cout << s[i];
      }
    } else {
      cout << "no";
    }

    return 0;
}
