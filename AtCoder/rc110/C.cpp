#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int n;
int a[200000];
int pos[200000];
bool used[200000];
int order[200000];
int orderidx = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    pos[a[i]] = i;
  }

  for (int i = 0; i < n - 1; i++) {
    if (used[i]) {
      if (a[i] != i) {
        cout << "-1" << nl;
        return 0;
      }
    } else {
      if (a[i] == i) {
        cout << "-1" << nl;
        return 0;
      }

      for (int j = pos[i] - 1; j >= i; j--) {
        swap(a[j], a[j + 1]);
        order[orderidx++] = j + 1;
        used[j] = true;
      }
    }
  }

  for (int i = 0; i < orderidx; i++)
    cout << order[i] << nl;

  return 0;
}

