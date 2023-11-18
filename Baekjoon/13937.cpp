#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define vi vector<int>
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)

const ll inf = 1e9;
ll N;

ll n, q, s;
ll toq[101];
ll maxq[101];
vector<vector<ll>> capacity, flow;
vector<ll> height, excess;

struct PushRelabel {
  struct Edge {
    ll dest, back;
    ll f, c;
  };
  vector<vector<Edge>> g;
  vector<ll> ec;
  vector<Edge*> cur;
  vector<vi> hs; vi H;
  PushRelabel(ll n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

  void addEdge(ll s, ll t, ll cap, ll rcap=0) {
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
  ll calc(ll s, ll t) {
    ll v = sz(g); H[s] = v; ec[t] = 1;
    vi co(2*v); co[0] = v-1;
    rep(i,0,v) cur[i] = g[i].data();
    for (Edge& e : g[s]) addFlow(e, e.c);

    for (ll hi = 0;;) {
      while (hs[hi].empty()) if (!hi--) return -ec[s];
      ll u = hs[hi].back(); hs[hi].pop_back();
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
  bool leftOfMinCut(ll a) { return H[a] >= sz(g); }
};

int main() {

  cin >> n >> q >> s;
  N = n * (2 * q + 1) + 2;
  PushRelabel a(N);
  capacity.assign(N, vector<ll>(N, 0));

  for (int i = 0; i < s; i++) {
    cin >> toq[i];
    toq[i]--;
  }

  for (int i = 0; i < q; i++) {
    cin >> maxq[i];
  }

  ll source = n * (2 * q + 1);
  ll sink = n * (2 * q + 1) + 1;
  ll dn = (2 * q + 1);

  ll sens = 0;
  for (int i = 0; i < n; i++) {
    ll d;
    cin >> d;
    a.addEdge(dn * i + 2 * q, sink, d);

    vector<ll> tmp(q, 0);
    for (int j = 0; j < s; j++) {
      ll x;
      cin >> x;
      sens += x;
      tmp[toq[j]] += x;
    }

    for (int j = 0; j < q; j++) {
      a.addEdge(source, dn * i + j, tmp[j]);
      a.addEdge(dn * i + j, dn * i + j + q, maxq[j]);
      a.addEdge(dn * i + j + q, dn * i + 2 * q, maxq[j]);
      if (i < n - 1)
        a.addEdge(dn * i + j + q, dn * (i + 1) + j, maxq[j]);
    }
  }

  cout << (a.calc(source, sink) == sens ? "possible" : "impossible");

  return 0;
}
