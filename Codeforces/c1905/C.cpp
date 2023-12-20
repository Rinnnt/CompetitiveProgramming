#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      string s;
      cin >> s;

      deque<pair<char, int>> st;
      for (int i = 0; i < n; i++) {
        while (!st.empty() && s[i] > st.back().first) {
          st.pop_back();
        }
        st.push_back({s[i], i});
      }

      char prev = '0';
      int idx = st.size() - 1;
      bool sorted = true;
      for (int i = 0; i < n; i++) {
        if (idx >= 0 && i == st[st.size() - idx - 1].second) {
          if (st[idx].first < prev) {
            sorted = false;
            break;
          }
          prev = st[idx].first;
          idx--;
        } else {
          if (s[i] < prev) {
            sorted = false;
            break;
          }
          prev = s[i];
        }
      }

      if (sorted) {
        int idx = 0;
        while (idx < st.size() - 1 && st[idx].first == st[idx + 1].first) idx++;
        cout << st.size() - idx - 1 << nl;
      } else {
        cout << -1 << nl;
      }

    }

    return 0;
}
