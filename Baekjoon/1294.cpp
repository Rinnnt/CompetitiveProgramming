#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<string> ss(n);
  for (auto &s : ss) cin >> s;

  priority_queue<string, vector<string>, greater<string>> q;
  for (auto s : ss) {
    q.push(s + 'a');
  }

  string res = "";
  while (!q.empty()) {
    string s = q.top();
    q.pop();

    if (s == "a") continue;

    res += s[0];
    string t = s.substr(1);
    if (t.size())
      q.push(t);
  }

  cout << res << nl;

  return 0;
}
