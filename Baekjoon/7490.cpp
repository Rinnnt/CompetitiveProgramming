#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int n; 
int op[10];

void solve(int x) {
  if (x >= n - 1) {
    int total = 0;
    int cur = 1;
    int prev_op = 0;
    for (int i = 0; i < n - 1; i++) {
      if (op[i] == 0) {
        if (prev_op == 0) {
          total += cur;
        } else {
          total -= cur;
        }
        prev_op = 0;
        cur = 2 + i;
      } else if (op[i] == 1) {
        if (prev_op == 0) {
          total += cur;
        } else {
          total -= cur;
        }
        prev_op = 1;
        cur = 2 + i;
      } else {
        cur *= 10;
        cur += 2 + i;
      }
    }
    if (prev_op == 0) {
      total += cur;
    } else {
      total -= cur;
    }

    if (total == 0) {
      cout << "1";
      for (int i = 0; i < n - 1; i++) {
        if (op[i] == 0) {
          cout << "+";
        } else if (op[i] == 1) {
          cout << "-";
        } else {
          cout << " ";
        }
        cout << 2 + i;
      }
      cout << nl;
    }
    return;
  }

  op[x] = 2;
  solve(x + 1);
  op[x] = 0;
  solve(x + 1);
  op[x] = 1;
  solve(x + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    solve(0);
    cout << nl;
  }

  return 0;
}
