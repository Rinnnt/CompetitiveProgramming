#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int used[200001];
int av[200001];
int bv[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      for (int i = 0; i < 200001; i++)
        used[i] = false;

      int n;
      cin >> n;

      priority_queue<pair<int, int>> a;
      for (int i = 0; i < n; i++) {
        cin >> av[i];
      }

      priority_queue<pair<int, int>> b;
      for (int i = 0; i < n; i++) {
        cin >> bv[i];
      }

      for (int i = 0; i < n; i++) {
        a.push({av[i] + bv[i] - 1, i});
      }

      for (int i = 0; i < n; i++) {
        b.push({bv[i] + av[i] - 1, i});
      }

      bool alice = true;
      ll score = 0;
      for (int i = 0; i < n; i++) {
        if (alice) {
          while (used[a.top().second]) a.pop();
          score += av[a.top().second] - 1;
          used[a.top().second] = true;
          alice = !alice;
        } else {
          while (used[b.top().second]) b.pop();
          score -= bv[b.top().second] - 1;
          used[b.top().second] = true;
          alice = !alice;
        }
      }

      cout << score << nl;
    }

    return 0;
}
