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

  int n;
  cin >> n;
  bool win = false;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2)
      win = true;
  }

  cout << (win ? "first" : "second") << nl;

  return 0;
}

