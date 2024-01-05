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

  ll h, w;
  cin >> h >> w;

  ll ans = 1e15;
  for (int i = 1; i < h; i++) {
    ll a = w * i;
    ll b = w * ((h - i) / 2);
    ll c = w * ((h - i + 1) / 2);
    ans = min(ans, max(a, max(b, c)) - min(a, min(b, c)));

    ll d = (h - i) * (w / 2);
    ll e = (h - i) * ((w + 1) / 2);
    ans = min(ans, max(a, max(d, e)) - min(a, min(d, e)));
  }

  for (int i = 1; i < w; i++) {
    ll a = h * i;
    ll b = h * ((w - i) / 2);
    ll c = h * ((w - i + 1) / 2);
    ans = min(ans, max(a, max(b, c)) - min(a, min(b, c)));

    ll d = (w - i) * (h / 2);
    ll e = (w - i) * ((h + 1) / 2);
    ans = min(ans, max(a, max(d, e)) - min(a, min(d, e)));
  }

  cout << ans << nl;

  return 0;
}

