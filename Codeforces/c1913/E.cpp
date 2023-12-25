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

int b[51][51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int source = n + m;
    int sink = n + m + 1;

    int original_sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
        original_sum += b[i][j];
        edges.push_back({i, n + j, 1, (b[i][j] ? 0 : 1)});
      }
    }

    int at = 0;
    int bt = 0;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      edges.push_back({source, i, a[i], 0});
      at += a[i];
    }
    for (int j = 0; j < m; j++) {
      cin >> b[j];
      edges.push_back({n + j, sink, b[j], 0});
      bt += b[j];
    }

    pair<int, int> mcmf = min_cost_flow(n + m + 2, edges, INF, source, sink);
    if (mcmf.first != at || mcmf.first != bt) {
      cout << -1 << nl;
      return 0;
    }

    // 0 -> 1 : cost
    // 1 -> 0 : original_sum - (flow - cost)
    // sum of changes
    cout << original_sum - mcmf.first + mcmf.second * 2 << nl;

    return 0;
}
