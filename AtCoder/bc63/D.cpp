#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

ll A[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, a, b;
  cin >> n >> a >> b;

  for (int i = 0; i < n; i++) cin >> A[i];

  ll l = 0;
  ll r = 1e9;
  while (l + 1 < r) {
    ll mid = (l + r) / 2;

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (max(0LL, A[i] - b * mid) + (a - b - 1)) / (a - b);
    }

    if (cnt <= mid)
      r = mid;
    else
      l = mid;
  }

  cout << r << nl;

  return 0;
}

