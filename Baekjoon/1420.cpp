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

int n, m;

vector<pair<int, int>> dxys = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

int inbound(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int vnum(int i, int j, bool in) {
  return i * m + j + (in ? n * m : 0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  struct PushRelabel pr = PushRelabel(2 * n * m);

  bool pos = true;

  int source;
  int sink;
  vector<string> board(n);
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '#') continue;
      pr.addEdge(vnum(i, j, true), vnum(i, j, false), 1);
      if (board[i][j] == 'H') {
        for (auto dxy : dxys) {
          int ni = i + dxy.first;
          int nj = j + dxy.second;
          if (inbound(ni, nj) && board[ni][nj] == 'K')
            pos = false;
        }
        sink = vnum(i, j, true);
        continue;
      }
      if (board[i][j] == 'K') source = vnum(i, j, false);
      for (auto dxy : dxys) {
        int ni = i + dxy.first;
        int nj = j + dxy.second;
        if (inbound(ni, nj))
          pr.addEdge(vnum(i, j, false), vnum(ni, nj, true), 1);
      }
    }
  }

  if (pos) {
    cout << pr.calc(source, sink) << nl;
  } else {
    cout << -1 << nl;
  }

  return 0;
}
