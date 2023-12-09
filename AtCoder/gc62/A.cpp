#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s[s.size() - 1] == 'A') {
      cout << "A" << nl;
    } else {
      bool exists = false;
      for (int i = 0; i < s.size() - 1; i++)
        if (s[i] == 'B' && s[i + 1] == 'A')
          exists = true;
      if (exists)
        cout << "A" << nl;
      else
        cout << "B" << nl;
    }
  }

  return 0;
}

