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
  int n = s.size();
  int cnt = 1;
  vector<int> cnts;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) cnt++;
    else cnts.push_back(cnt), cnt = 1;
  }
  cnts.push_back(cnt);

  vector<int> prefs;
  prefs.push_back(0);
  for (auto cnt : cnts)
    prefs.push_back(prefs.back() + cnt);

  int mx = 0;
  for (int i = 0; i < cnts.size(); i++) {
    mx = max(mx, min(prefs[i + 1], n - prefs[i]));
  }
  cout << mx << nl;

  return 0;
}

