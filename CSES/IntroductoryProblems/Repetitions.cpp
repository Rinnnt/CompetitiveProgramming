#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    ll run = 0;
    ll m = 0;
    char prev = '#';
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == prev) {
        run++;
      } else {
        run = 1;
      }
      m = max(run, m);
      prev = s[i];
    }
    cout << m;

    return 0;
}