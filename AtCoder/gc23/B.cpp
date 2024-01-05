#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

string b[301];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int ans = 0;
  for (int k = 0; k < n; k++) {
    bool good = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (b[i][(k + j) % n] != b[j][(k + i) % n])
          good = false;
      }
    }
    if (good) ans++;
  }

  cout << n * ans << nl;

  return 0;
}

