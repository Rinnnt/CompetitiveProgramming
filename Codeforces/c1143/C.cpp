#include <bits/stdc++.h>
using namespace std;

#define ll long long

static vector<vector<int>> al;
static vector<int> cs;
static vector<int> res;

void removable(int root) {
  int b = cs[root];
  for (int i = 0; i < al[root].size(); i++) {
    b &= cs[al[root][i]];
    removable(al[root][i]);
  }

  if (b == 1) {
    res.push_back(root);
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, p, c;
    cin >> n;

    for (int i = 0; i < n + 1; i++) {
      vector<int> v;
      al.push_back(v);
      cs.push_back(0);
    }

    int root;

    for (int i = 0; i < n; i++) {
      cin >> p >> c;
      if (p == -1) {
        root = i + 1;
      } else {
        al[p].push_back(i + 1);
      }
      cs[i + 1] = c;
    }

    removable(root);

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++) {
      cout << res[i] << " ";
    }

    if (res.size() == 0) {
      cout << "-1";
    }

    return 0;
}
