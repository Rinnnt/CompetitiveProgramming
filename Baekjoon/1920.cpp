#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  set<int> s;
  while (n--) {
    int x;
    cin >> x;
    s.insert(x);
  }
  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    if (s.count(x)) {
      cout << 1;
    } else {
      cout << 0;
    }
    cout << nl;
  }
}
