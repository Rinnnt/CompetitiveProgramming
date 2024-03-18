#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n, k;
      cin >> n >> k;

      vector<int> as(2 * n);
      vector<bool> ls(n + 1, false);
      vector<bool> rs(n + 1, false);
      for (int i = 0; i < n; i++) {
        cin >> as[i];
        ls[as[i]] = true;
      }
      for (int i = n; i < 2 * n; i++) {
        cin >> as[i];
        rs[as[i]] = true;
      }

      vector<int> left;
      vector<int> right;
      for (int i = 1; i <= n; i++) {
        if (ls[i] && !rs[i]) {
          left.push_back(i);
          left.push_back(i);
        }
        if (rs[i] && !ls[i]) {
          right.push_back(i);
          right.push_back(i);
        }
      }

      for (int i = 1; i <= n; i++) {
        if (ls[i] && rs[i]) {
          left.push_back(i);
          right.push_back(i);
        }
      }

      for (int i = 0; i < 2 * k; i++) {
        cout << left[i] << " ";
      }
      cout << nl;

      for (int i = 0; i < 2 * k; i++) {
        cout << right[i] << " ";
      }
      cout << nl;


    }

    return 0;
}
