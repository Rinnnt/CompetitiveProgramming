#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  int parity = s.size() % 2;
  int final_parity = (s[0] == s.back() ? 1 : 0);

  if (parity == final_parity)
    cout << "Second" << nl;
  else
    cout << "First" << nl;

  return 0;
}

