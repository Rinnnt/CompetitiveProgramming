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

  int r;
  cin >> r;
  for (int i = 1; i < n; i++) {
    int k;
    cin >> k;
    cout << r / __gcd(r, k) << "/" << k / __gcd(r, k) << nl;
  }

  return 0;
}

