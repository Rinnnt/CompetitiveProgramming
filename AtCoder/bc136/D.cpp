#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int ans[100001] = {};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'R' && s[i + 1] == 'L') {
      ans[i]++;
      ans[i + 1]++;
      int l = i - 1;
      while (l >= 0 && s[l] == 'R')
        ans[i + ((i - l--) % 2)]++;

      int r = i + 2;
      while (r < s.size() && s[r] == 'L')
        ans[i + ((r++ - i) % 2)]++;
    }
  }

  for (int i = 0; i < s.size(); i++)
    cout << ans[i] << " ";
  cout << nl;

  return 0;
}

