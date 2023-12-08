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

  string a, b;
  cin >> a >> b;
  ll an = 3600LL * stoi(a.substr(0, 2)) + 60 * stoi(a.substr(3, 2)) + stoi(a.substr(6, 2));
  ll bn = 3600LL * stoi(b.substr(0, 2)) + 60 * stoi(b.substr(3, 2)) + stoi(b.substr(6, 2));

  ll c = bn - an;
  if (c < 0) c += 24LL * 3600;

  ll h = c / 3600;
  ll m = (c % 3600) / 60;
  ll s = c % 60;

  if (h + m + s == 0)
    cout << "24:00:00" << nl;
  else
    cout << (h < 10 ? "0" : "") << h << ":"
         << (m < 10 ? "0" : "") << m << ":"
         << (s < 10 ? "0" : "") << s << nl;

  return 0;
}

