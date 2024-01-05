#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[17];
vector<int> startsWith[26];
vector<int> endsWith[26];
bool winning[17][1 << 16];
bool visited[17][1 << 16];

void dfs(int cur, int used) {
  visited[cur][used] = true;
  winning[cur][used] = true;
  for (auto x : edges[cur]) {
    if ((used & (1 << (x - 1))) == 0) {
      int nused = used | (1 << (x - 1));
      if (!visited[x][nused])
        dfs(x, nused);
      if (winning[x][nused])
        winning[cur][used] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (auto x : startsWith[s.back() - 'a'])
      edges[i].push_back(x);
    for (auto x : endsWith[s[0] - 'a'])
      edges[x].push_back(i);
    startsWith[s[0] - 'a'].push_back(i);
    endsWith[s.back() - 'a'].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    dfs(i, (1 << (i - 1)));

    if (winning[i][(1 << (i - 1))]) {
      cout << "First" << nl;
      return 0;
    }
  }

  cout << "Second" << nl;

  return 0;
}

