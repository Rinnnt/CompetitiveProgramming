#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int a[2001];
bool palindrome[2001][2001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    palindrome[i][i] = true;
  }

  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == a[i + 1]) {
      palindrome[i][i + 1] = true;
    }
  }

  for (int len = 3; len <= n; len++) {
    for (int s = 1; s + len - 1 <= n; s++) {
      palindrome[s][s + len - 1] = a[s] == a[s + len - 1] && palindrome[s + 1][s + len - 2];
    }
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;
    cout << palindrome[s][e] << nl;
  }

  return 0;
}

