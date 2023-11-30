#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)

pair<ll, vll> hungarian(const vector<vll> &a) {
	if (a.empty()) return {0, {}};
	ll n = sz(a) + 1, m = sz(a[0]) + 1;
	vll u(n), v(m), p(m), ans(n - 1);
	rep(i,1,n) {
		p[0] = i;
		ll j0 = 0; // add "dummy" worker 0
		vll dist(m, LONG_MAX), pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			ll i0 = p[j0], j1, delta = LONG_MAX;
			rep(j,1,m) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			rep(j,0,m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			ll j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<vll> prob(n, vll(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ld p;
      cin >> p;
      p /= 100;
      p = (p > 0 ? log(p) : -1000000);
      p *= 100000000000;
      prob[i][j] = (ll)-p;
      // prob[i][j] /= 100;
      // prob[i][j] *= -1;
    }
  }

//   for (auto v : prob) {
//     for (auto x : v)
//       cout << x <<  " ";
//     cout << nl;
//   }

  cout << fixed << setprecision(15) << exp(((ld)-hungarian(prob).first) / 100000000000) * 100 << nl;

  return 0;
}
