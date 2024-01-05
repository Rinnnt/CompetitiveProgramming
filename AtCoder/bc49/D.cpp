#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int road_p[200001];
int road_sz[200001];
int rail_p[200001];
int rail_sz[200001];
bool visited[200001];

vector<int> roads[200001];
vector<int> rails[200001];

void make_set(int *dsu, int *sz, int v) {
  dsu[v] = v;
  sz[v] = 1;
}

int find_set(int *dsu, int v) {
  if (dsu[v] == v)
    return v;
  return dsu[v] = find_set(dsu, dsu[v]);
}

void union_set(int *dsu, int *sz, int a, int b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  dsu[b] = a;
  sz[a] += sz[b];
}

void roads_dfs(int cur, int parent) {
  visited[cur] = true;
  union_set(road_p, road_sz, cur, parent);
  for (auto x : roads[cur]) {
    if (!visited[x]) {
      roads_dfs(x, parent);
    }
  }
}

void rails_dfs(int cur, int parent) {
  visited[cur] = true;
  union_set(rail_p, rail_sz, cur, parent);
  for (auto x : rails[cur]) {
    if (!visited[x]) {
      rails_dfs(x, parent);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k, l;
  cin >> n >> k >> l;
  for (int i = 0; i < k; i++) {
    int p, q;
    cin >> p >> q;
    roads[p].push_back(q);
    roads[q].push_back(p);
  }

  for (int i = 0; i < l; i++) {
    int r, s;
    cin >> r >> s;
    rails[r].push_back(s);
    rails[s].push_back(r);
  }

  for (int i = 1; i <= n; i++) {
    make_set(road_p, road_sz, i);
    make_set(rail_p, rail_sz, i);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      roads_dfs(i, i);
    }
  }

  for (int i = 1; i <= n; i++) visited[i] = false;

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      rails_dfs(i, i);
    }
  }

  map<pii, int> group;
  for (int i = 1; i <= n; i++) {
    group[{find_set(road_p, i), find_set(rail_p, i)}]++;
  }

  for (int i = 1; i <= n; i++) {
    cout << group[{find_set(road_p, i), find_set(rail_p, i)}] << " ";
  }
  cout << nl;

  return 0;
}

