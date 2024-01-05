#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

ll combs[55][55];

ll comb(ll n, ll r) {
  if (combs[n][r] != -1) return combs[n][r];
  if (r == 0) return combs[n][r] = 1;
  if (n == r) return combs[n][r] = 1;
  return combs[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 55; i++) {
    for (int j = 0; j < 55; j++) {
      combs[i][j] = -1;
    }
  }

  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  map<ll, int> freq;
  for (auto &x : v) {
    cin >> x;
    freq[x]++;
  }

  sort(v.rbegin(), v.rend());

  ll maxsum = 0;
  ll maxnum = 1;
  ll maxcnt = 0;
  for (int i = a; i <= b; i++) {
    ll sum = 0;
    int j;
    for (j = 0; j < i; j++) {
      sum += v[j];
    }
    ll used = 1;
    j--;
    while (j > 0 && v[j] == v[j - 1]) {
      used++;
      j--;
    }

    ll cnt = comb(freq[v[i - 1]], used);

    if (maxsum * i < sum * maxnum) {
      maxsum = sum;
      maxnum = i;
      maxcnt = cnt;
    } else if (maxsum * i == sum * maxnum) {
      maxcnt += cnt;
    }
  }

  cout << fixed << setprecision(15);
  cout << ((ld)maxsum) / maxnum << nl;
  cout << maxcnt << nl;

  return 0;
}

