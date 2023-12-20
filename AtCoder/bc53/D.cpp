#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int cnt[100001] = {};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int d = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (cnt[x]++ == 0) d++;
  }

  int even = 0;
  for (int i = 0; i < 100001; i++)
    if (cnt[i] != 0 && cnt[i] % 2 == 0)
      even++;

  if (even % 2)
    cout << d - 1 << nl;
  else
    cout << d << nl;


  return 0;
}

