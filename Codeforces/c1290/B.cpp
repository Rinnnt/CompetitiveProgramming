#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;

    vector<vector<int>> cnt(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        cnt[i][j] = cnt[i - 1][j];
      }
      cnt[i][s[i - 1] - 'a']++;
    }

    while (q--) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      if (l == r || s[l] != s[r]) {
        cout << "Yes" << nl;
      } else {
        int distinct = 0;
        for (int i = 0; i < 26; i++)
          if (cnt[r + 1][i] != cnt[l][i])
            distinct++;
        if (distinct >= 3)
          cout << "Yes" << nl;
        else
          cout << "No" << nl;
      }
    }

    return 0;
}
