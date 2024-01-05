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

  int K, n;
  cin >> n >> K;
  vector<ll> xs(n);
  vector<ll> sorted_xs(n);
  vector<ll> ys(n);
  vector<ll> sorted_ys(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i] >> ys[i];
    sorted_xs[i] = xs[i];
    sorted_ys[i] = ys[i];
  }

  sort(sorted_xs.begin(), sorted_xs.end());
  sort(sorted_ys.begin(), sorted_ys.end());

  ll minarea = 5e18;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = k; l < n; l++) {
          int cnt = 0;
          for (int p = 0; p < n; p++) {
            if (xs[p] >= sorted_xs[i] && xs[p] <= sorted_xs[j]
                && ys[p] >= sorted_ys[k] && ys[p] <= sorted_ys[l])
              cnt++;
          }
          if (cnt >= K)
            minarea = min(minarea, (sorted_xs[j] - sorted_xs[i]) * (sorted_ys[l] - sorted_ys[k]));
        }
      }
    }
  }

  cout << minarea << nl;

  return 0;
}

