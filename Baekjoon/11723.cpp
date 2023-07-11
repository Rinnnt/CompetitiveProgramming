#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int m;
  cin >> m;
  set<int> s;
  while (m--) {
    string op;
    cin >> op;
    if (op == "add") {
      int x;
      cin >> x;
      s.insert(x);
    }
    if (op == "remove") {
      int x;
      cin >> x;
      s.erase(x);
    }
    if (op == "check") {
      int x;
      cin >> x;
      if (s.count(x)) {
        cout << 1 << nl;
      } else {
        cout << 0 << nl;
      }
    }
    if (op == "toggle") {
      int x;
      cin >> x;
      if (s.count(x)) {
        s.erase(x);
      } else{
        s.insert(x);
      }
    }
    if (op == "all") {
      for (int i = 1; i <= 20; i++) {
        s.insert(i);
      }
    }
    if (op == "empty") {
      s.clear();
    }

  }

}
