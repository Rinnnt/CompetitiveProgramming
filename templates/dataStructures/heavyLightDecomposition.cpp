#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'

int n, m, pv;
int c[100001];
int t[4 * 100001];

void build(int ti, int tl, int tr) {
    if (tl == tr) {
        t[ti] = -1e9;
        return;
    }
    
    int mid = (tl + tr) / 2;
    build(2 * ti + 1, tl, mid);
    build(2 * ti + 2, mid + 1, tr);
    t[ti] = max(t[2 * ti + 1], t[2 * ti + 2]);
}

void update(int ti, int tl, int tr, int idx, int v) {
    if (tl == tr && tl == idx) {
        t[ti] = v;
        return;
    }
    
    int mid = (tl + tr) / 2;
    if (idx <= mid) update(2 * ti + 1, tl, mid, idx, v);
    else update(2 * ti + 2, mid + 1, tr, idx, v);
    t[ti] = max(t[2 * ti + 1], t[2 * ti + 2]);
}

int query(int ti, int tl, int tr, int l, int r) {
    if (l > r) return -1e9;
    if (tl == l && tr == r) return t[ti];
    
    int mid = (tl + tr) / 2;
    int q1 = query(2 * ti + 1, tl, mid, l, min(mid, r));
    int q2 = query(2 * ti + 2, mid + 1, tr, max(l, mid + 1), r);
    return max(q1, q2);
}
pii edges[100001];
vector<pii> inp[100001];
vector<int> g[100001];
int sz[100001], dep[100001], par[100001], top[100001], in[100001], out[100001];

void dfs(int v, int p) {
    for (auto &[u, w] : inp[v]) {
        if (u != p) {
            g[v].push_back(u);
            c[u] = w;
            dfs(u, v);
        }
    }
}

void dfs1(int v) {
    sz[v] = 1;
    for (auto &u : g[v]) {
        dep[u] = dep[v] + 1;
        par[u] = v;
        dfs1(u);
        sz[v] += sz[u];
        if (sz[u] > sz[g[v][0]]) swap(u, g[v][0]);
    }
}

void dfs2(int v) {
    in[v] = ++pv;
    for (auto u : g[v]) {
        top[u] = u == g[v][0] ? top[v] : u;
        dfs2(u);
    }
    out[v] = pv;
}

void update_hld(int v, int w) {
    update(0, 0, pv, in[v], w);
}

int query_hld(int a, int b) {
    int ret = 0;
    while (top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret = max(ret, query(0, 0, pv, in[st], in[a]));
        a = par[st];
    }
    if (dep[a] > dep[b]) swap(a, b);
    ret = max(ret, query(0, 0, pv, in[a] + 1, in[b]));
    return ret;
}

void solveProblem() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        inp[u].push_back({v, w});
        inp[v].push_back({u, w});
        edges[i] = {u, v};
    }
    
    dfs(1, -1);
    dfs1(1);
    top[1] = 1;
    dfs2(1);
    
    build(0, 0, pv);
    for (int i = 1; i <= n; i++)
        update(0, 0, pv, in[i], c[i]);
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            a--;
            if (edges[a].first == par[edges[a].second]) {
                update_hld(edges[a].second, b);
            } else {
                update_hld(edges[a].first, b);
            }
        } else {
            cout << query_hld(a, b) << nl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solveProblem();
    }
    
    return 0;
}
