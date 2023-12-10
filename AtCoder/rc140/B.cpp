#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
    int n;
    string s;
    cin >> n >> s;

    multiset<int> st;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        int c = 1;
        while (i - c >= 0 && s[i - c] == 'A'
            && i + c < n && s[i + c] == 'C')
          c++;
        if (c - 1) st.insert(c - 1);
      }
    }

    int ans = 0;
    while (!st.empty()) {
      int x = *st.rbegin();
      st.erase(st.find(x));
      ans++;

      if (--x > 0) st.insert(x);

      if (st.empty()) break;

      x = *st.begin();
      st.erase(st.find(x));
      ans++;
    }

    cout << ans << nl;

    return 0;
}

