#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int lcs[1001][1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string a, b;
  cin >> a >> b;

  for (int i = 0; i <= a.size(); i++) {
    for (int j = 0; j <= b.size(); j++) {
      lcs[i][j] = 0;
    }
  }

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      if (a[i] == b[j]) { 
        lcs[i + 1][j + 1] = lcs[i][j] + 1;
      } else {
        lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
      }
    }
  }

  cout << lcs[a.size()][b.size()];

  return 0;
}
