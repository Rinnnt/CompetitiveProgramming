#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int n;

void dfs(string s, char mx) {
  if (s.size() == n) {
    cout << s << nl;
  }
  else {
    for (char c = 'a'; c <= mx; c++) {
      dfs(s + c, (c == mx ? mx + 1 : mx));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  dfs("", 'a');

  return 0;
}

