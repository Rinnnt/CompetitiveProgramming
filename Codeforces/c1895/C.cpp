#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

bool cmp(string a, string b) {
  return a.size() < b.size();
}

int sums[6][100000] = {};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll ans = 0;

    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) {
      cin >> x;
    }

    sort(a.begin(), a.end(), cmp);

    for (auto x : a) {
      int v = 0;
      for (auto c : x)
        v += c - '0';

      sums[x.size()][v]++;

      if (x.size() == 1)
        ans += 2 * sums[1][v] - 1;
      else if (x.size() == 2)
        ans += 2 * sums[2][v] - 1;
      else if (x.size() == 3) {
        ans += 2 * sums[3][v] - 1;
        int tmp = x[0] - '0';
        if (v - 2 * tmp > 0)
          ans += sums[1][v - 2 * tmp];
        tmp += x[1] - '0';
        if (v - tmp < tmp)
          ans += sums[1][tmp - (v - tmp)];
      } else if (x.size() == 4) {
        ans += 2 * sums[4][v] - 1;
        int tmp = x[0] - '0';
        if (v - 2 * tmp > 0)
          ans += sums[2][v - 2 * tmp];
        tmp += x[1] - '0';
        tmp += x[2] - '0';
        if (v - tmp < tmp)
          ans += sums[2][tmp - (v - tmp)];
      } else {
        ans += 2 * sums[5][v] - 1;
        int tmp = x[0] - '0';
        if (v - 2 * tmp > 0)
          ans += sums[3][v - 2 * tmp];
        tmp += x[1] - '0';
        if (v - 2 * tmp > 0)
          ans += sums[1][v - 2 * tmp];
        tmp += x[2] - '0';
        if (v - tmp < tmp)
          ans += sums[1][tmp - (v - tmp)];
        tmp += x[3] - '0';
        if (v - tmp < tmp)
          ans += sums[3][tmp - (v - tmp)];
      }
    }

    cout << ans << nl;

    return 0;
}
