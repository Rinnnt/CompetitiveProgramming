#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string rgb = "RGB";

    int n;
    cin >> n;
    string s;
    cin >> s;
    s += '$';

    char last = '.';
    int l = 1;
    int ans = 0;
    string t;
    for (int i = 0; i < n + 1; i++) {
      if (s[i] == last) l++;
      else {
        char cc = '.';
        for (auto a : rgb)
          if (a != last && a != s[i]) cc = a;
        for (int i = 0; i < l; i++) {
          if (i % 2) {
            t += cc;
          } else {
            t += last;
          }
        }
        ans += l / 2;
        l = 1;
        last = s[i];
      }
    }

    cout << ans << nl;
    for (int i = 1; i < t.size(); i++) {
      cout << t[i];
    }
    cout << nl;

    return 0;
}
