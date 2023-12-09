#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  ll n = 0;
  int as = 0;
  int i = 0;

  while (i < ((int)s.size()) - 2) {
    if (s[i] == 'A') as++;
    else as = 0;

    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      n += as;
      s[i] = 'B';
      s[i + 1] = 'C';
      s[i + 2] = 'A';
      i += 2;
      as -= 1;
    } else {
      i += 1;
    }
  }

  cout << n << nl;

  return 0;
}

