#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i <(b); ++i)
#define sz(x) (int)(x).size()

const int inf = 1e9;

// Push Relabel Algorithm from Kactl team notes
// https://github.com/kth-competitive-programming/kactl/blob/main/kactl.pdf

struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, ll f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		for (Edge& e : g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> vuln(n, false);
    for (auto &x : a)
      cin >> x;

    vector<vector<int>> edges(n, vector<int>());
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++)
        if (s[j] == 'Y')
          edges[i].push_back(j);
    }

    for (int i = 0; i < n; i++) {
      if (a[i] == 0) continue;

      for (auto x : edges[i])
        if (a[x] == 0)
          vuln[i] = true;
    }

    int rs = 0;
    int vs = 0;
    for (int i = 0 ; i < n; i++) {
      if (a[i] > 0) rs++;
      if (vuln[i]) vs++;
    }

    int l = -1, r = 100005;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      PushRelabel pr = PushRelabel(2 * n + 2);

      for (int i = 0; i < n; i++)
        if (a[i] > 0)
          pr.addEdge(2 * n, i, a[i]);

      for (int i = 0; i < n; i++)
        if (vuln[i])
          pr.addEdge(i + n, 2 * n + 1, mid);
        else if (a[i] > 0)
          pr.addEdge(i + n, 2 * n + 1, 1);

      for (int i = 0; i < n; i++)
        if (a[i] > 0)
          pr.addEdge(i, i + n, inf);

      for (int i = 0; i < n; i++)
        if (a[i] > 0)
          for (auto x : edges[i])
            if (a[x] > 0)
              pr.addEdge(i, x + n, inf);

      int mf = pr.calc(2 * n, 2 * n + 1);
      if (mf == vs * mid + (rs - vs))
        l = mid;
      else
        r = mid;
    }

    cout << l << nl;
  }

  return 0;
}
