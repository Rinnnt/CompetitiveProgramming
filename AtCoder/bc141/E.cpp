#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  int l = 0;
  int r = 2501;

  while (l + 1 < r) {
    int mid = (l + r) / 2;

    map<string, int> ss;
    bool exists = false;
    for (int i = 0; i < n - mid + 1; i++) {
      string subs = s.substr(i, mid);
      if (ss.count(subs)) {
        if (ss[subs] + mid - 1 < i) {
          exists = true;
          break;
        }
      } else {
        ss[subs] = i;
      }
    }

    if (exists)
      l = mid;
    else
      r = mid;
  }

  cout << l << nl;

  return 0;
}

