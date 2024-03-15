#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int ls[300001];
int dist[400001];
int parent[400001];
vector<int> edges[400001];
vector<int> primes;
bool is_prime[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 300001; i++)
      is_prime[i] = true;
    for (int i = 2; i < 300001; i++) {
      if (is_prime[i]) {
        primes.push_back(i);
        if ((long long)i * i < 300001) {
          for (int j = i * i; j < 300001; j += i)
            is_prime[j] = false;
        }
      }
    }

    int n;
    cin >> n;

    for (int i = 0; i < 400001; i++) {
      dist[i] = 1e9;
      parent[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
      cin >> ls[i];

      vector<int> factors;
      for (int j = 2; j * j <= ls[i]; j++) {
        if (ls[i] % j == 0) {
          factors.push_back(j);
          while (ls[i] % j == 0) ls[i] /= j;
        }
      }
      if (ls[i] != 1) factors.push_back(ls[i]);

      for (auto factor : factors) {
        int idx = lower_bound(primes.begin(), primes.end(), factor) - primes.begin();
        edges[300001 + idx].push_back(i);
        edges[i].push_back(300001 + idx);
      }
    }

    int s, t;
    cin >> s >> t;

    deque<int> q;
    q.push_back(s);
    dist[s] = 0;
    while (!q.empty()) {
      int c = q.front();
      q.pop_front();
      for (auto v : edges[c]) {
        if (dist[v] > dist[c] + 1) {
          dist[v] = dist[c] + 1;
          parent[v] = c;
          q.push_back(v);
        }
      }
    }

    if (dist[t] == 1e9)
      cout << -1 << nl;
    else {
      cout << dist[t] / 2 + 1 << nl;
      vector<int> ps;
      ps.push_back(t);
      while (parent[t] != -1) {
        t = parent[parent[t]];
        ps.push_back(t);
      }
      reverse(ps.begin(), ps.end());
      for (auto p : ps)
        cout << p << ' ';
      cout << nl;
    }

    return 0;
}
