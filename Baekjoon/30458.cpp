#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> c(26, 0);
  for (int i = 0; i < s.size() / 2; i++)
    c[s[i] - 'a']++;
  for (int i = (s.size() + 1) / 2; i < s.size(); i++)
    c[s[i] - 'a']++;

  bool possible = true;
  for (int i = 0; i < 26; i++)
    if (c[i] % 2)
      possible = false;

  cout << (possible ? "Yes" : "No") << nl;


  return 0;
}
