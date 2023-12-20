#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int deg[200001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
  }

  priority_queue<int> q;
  for (int i = 1; i <= n; i++)
    q.push(deg[i]);

  vector<int> a;
  while (n) {
    n -= q.top() + 1;
    a.push_back(q.top());
    q.pop();
  }

  for (int i = a.size() - 1; i >= 0; i--)
    cout << a[i] << " ";
  cout << nl;

  return 0;
}

