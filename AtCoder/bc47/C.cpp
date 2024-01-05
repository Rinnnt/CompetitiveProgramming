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
  int changes = 0;
  for (int i = 1; i < s.size(); i++)
    if (s[i] != s[i - 1])
      changes++;
  cout << changes << nl;

  return 0;
}

