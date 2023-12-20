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

  ll n, k;
  cin >> n >> k;

  vector<ll> fun(n + 1, 0);
  for (int i = 0; i < n; i++)
    cin >> fun[i];
  sort(fun.rbegin(), fun.rend());

  ll s = 0;
  for (int i = 1; i < n + 1; i++) {
    ll rides = min(i * (fun[i - 1] - fun[i]), k);
    ll t = (rides / i);
    s += i * (t * (2 * fun[i - 1] - (t - 1)) / 2);
    s += (rides % i) * (fun[i - 1] - t);
    k -= rides;
  }

  cout << s << nl;

  return 0;
}

