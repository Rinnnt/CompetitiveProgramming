#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> as(n);
    vector<int> ai(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> as[i];
      ai[as[i]] = i;
    }

    vector<int> bs(n);
    vector<int> bi(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> bs[i];
      bi[bs[i]] = i;
    }

    int l = 1;
    int li = bi[as[0]];
    for (int i = 1; i < n; i++) {
      if (bi[as[i]] > li) {
        li = bi[as[i]];
        l++;
      } else {
        break;
      }
    }

    cout << n - l << nl;

    return 0;
}
