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

  ll n = 50;

  ll k;
  cin >> k;
  ll q = k / n;
  ll r = k % n;
  vector<ll> a(n, q + n - 1);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        a[j] += n;
      else
        a[j]--;
    }
  }

  cout << n << nl;
  for (auto x : a)
    cout << x << " ";
  cout << nl;

  return 0;
}

