#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int a[2001];
int b[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {

      int n, k, d;
      cin >> n >> k >> d;

      for (int i = 0; i < n; i++)
        cin >> a[i];

      for (int i = 0; i < k; i++)
        cin >> b[i];

      int tmp = 0;
      for (int i = 0; i < n; i++)
        if (a[i] == i + 1)
          tmp++;

      int ans = tmp + (d - 1) / 2;
      for (int z = 0; z < min(d - 1, 4002); z++) {
        int tmp = 0;
        for (int i = 0; i < b[z % k]; i++)
          if (++a[i] == i + 1)
            tmp++;
        for (int i = b[z % k]; i < n; i++)
          if (a[i] == i + 1)
            tmp++;
        tmp += (d - z - 2) / 2;
        ans = max(ans, tmp);
      }

      cout << ans << nl;
    }

    return 0;
}

