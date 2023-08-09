#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int mod = 1000;

vector<vector<int>> matmul(vector<vector<int>> a, vector<vector<int>> b) {
  vector<vector<int>> c(a.size(), vector<int>(b[0].size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
      }
    }
  }
  return c;
}

vector<vector<int>> pow(vector<vector<int>> a, ll b) {
  if (b == 1) {
    return a;
  }
  vector<vector<int>> m = pow(a, b / 2);
  if (b % 2) {
    return matmul(matmul(m, m), a);
  } else {
    return matmul(m, m);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, b;
  cin >> n >> b;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    vector<int> r(n);
    for (int j = 0; j < n; j++) {
      cin >> r[j];
    }
    a[i] = r;
  }

  vector<vector<int>> res = pow(a, b);
  for (auto r : res) {
    for (auto v : r) {
      cout << v % mod << " ";
    }
    cout << nl;
  }

  return 0;
}
