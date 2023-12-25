#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

set<int> d;

bool valid(int n) {
  bool v = false;
  do {
    v |= (d.count(n % 10) > 0);
    n /= 10;
  } while (n > 0);
  return !v;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    d.insert(x);
  }

  while (!valid(n)) n++;

  cout << n << nl;

  return 0;
}

