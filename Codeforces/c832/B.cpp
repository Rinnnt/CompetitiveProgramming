#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string gstr;
    cin >> gstr;
    vector<bool> good(26, false);
    for (auto c : gstr)
      good[c - 'a'] = true;

    string pattern;
    cin >> pattern;

    int pattern_size = pattern.size();

    int n;
    cin >> n;
    while (n--) {
      string q;
      cin >> q;

      int q_size = q.size();

      bool matches = true;

      int li = 0;
      while (li < q_size && li < pattern_size && pattern[li] != '*') {
        if ((pattern[li] == '?' && !good[q[li] - 'a'])
            || (pattern[li] != '?' && pattern[li] != q[li])) {
          matches = false;
          break;
        }
        li++;
      }

      if (!matches || (li == q_size && li < pattern_size && pattern[li] != '*')) {
        cout << "NO" << nl;
      } else if (matches && li == pattern_size && li == q_size) {
        cout << "YES" << nl;
      } else {
        // there exists a '*'

        int ri = pattern_size - 1;
        int qi = q_size - 1;
        while (qi >= 0 && pattern[ri] != '*') {
          if ((pattern[ri] == '?' && !good[q[qi] - 'a'])
              || (pattern[ri] != '?' && pattern[ri] != q[qi])) {
            matches = false;
            break;
          }
          ri--;
          qi--;
        }

        if (!matches || li > qi + 1 || pattern[ri] != '*') {
          cout << "NO" << nl;
        } else {
          for (int i = li; i <= qi; i++) {
            if (good[q[i] - 'a']) {
              matches = false;
              break;
            }
          }

          if (matches) {
            cout << "YES" << nl;
          } else {
            cout << "NO" << nl;
          }
        }
      }

    }


    return 0;
}
