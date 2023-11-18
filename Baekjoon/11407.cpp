#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nl '\n'

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;
vector<Edge> edges;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

pair<int, int> min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    return {flow, cost};
    // if (flow < K)
    //     return -1;
    // else
    //     return cost;
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  vector<int> b(m);
  vector<vector<int>> c(m, vector<int>(n));
  vector<vector<int>> d(m, vector<int>(n));

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> c[i][j];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> d[i][j];

  for (int i = 0; i < m; i++)
    edges.push_back({i + n, n + m + 1, b[i], 0});

  for (int j = 0; j < n; j++)
    edges.push_back({n + m, j, a[j], 0});

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      edges.push_back({j, i + n, c[i][j], d[i][j]});

  pair<int, int> mf = min_cost_flow(n + m + 2, edges, INF, n + m, n + m + 1);

  cout << mf.first << nl;
  cout << mf.second << nl;

  return 0;
}
