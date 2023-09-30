#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int e[400001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int w, n;
  cin >> w >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  for (int i = 0; i < 400001; i++) {
    e[i] = -1;
  }

  bool possible = false;
  for (int i = 0; i < a.size(); i++) {
    for (int j = i + 1; j < a.size(); j++) {
      int s = a[i] + a[j];
      int t = w - s;
      if (t > 1 && t < 400001 && e[t] != -1 && e[t] < i) {
        possible = true;
        break;
      }
      if (e[s] == -1) {
        e[s] = j;
      } else {
        e[s] = min(e[s], j);
      }
    }
    if (possible) {
      break;
    }
  }

  cout << (possible ? "YES" : "NO");

  return 0;
}
