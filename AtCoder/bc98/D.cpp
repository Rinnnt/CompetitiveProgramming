#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int cnt[20];

bool valid() {
  for (int i = 0; i < 20; i++) {
    if (cnt[i] > 1) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int l = 0;
  ll ans = 0;
  for (int r = 0; r < n; r++) {
    for (int i = 0; i < 20; i++) {
      if (a[r] >> i & 1) cnt[i]++;
    }

    while (!valid()) {
      for (int i = 0; i < 20; i++) {
        if (a[l] >> i & 1) cnt[i]--;
      }
      l++;
    }

    ans += r - l + 1;
  }

  cout << ans << nl;

  return 0;
}

