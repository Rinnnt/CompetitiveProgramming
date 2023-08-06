#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int left_zero[200001];
int right_one[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n, m;
      cin >> n >> m;
      string s;
      cin >> s;
      left_zero[0] = (s[0] == '0' ? 0 : -1);
      for (int i = 1; i < n; i++) {
        left_zero[i] = (s[i] == '0' ? i : left_zero[i - 1]);
      }
      right_one[n - 1] = (s[n - 1] == '1' ? n - 1 : n);
      for (int i = n - 2; i >= 0; i--) {
        right_one[i] = (s[i] == '1' ? i : right_one[i + 1]);
      }

      set<pair<int, int>> uniqs;
      for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int lb = right_one[l];
        int rb = left_zero[r];
        if (lb > rb) {
          lb = -1;
          rb = -1;
        }
        uniqs.insert({lb, rb});
      }
      cout << uniqs.size() << nl;
    }

    return 0;
}
