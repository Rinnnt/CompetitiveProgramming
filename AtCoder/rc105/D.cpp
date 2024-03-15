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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto &x : a) {
      cin >> x;
      cnt[x]++;
    }
    if (n % 2)
      cout << "Second" << nl;
    else {
      bool all_even = true;
      for (auto x : cnt)
        if (x.second % 2)
          all_even = false;
      if (all_even)
        cout << "Second" << nl;
      else
        cout << "First" << nl;
    }
  }

  return 0;
}
