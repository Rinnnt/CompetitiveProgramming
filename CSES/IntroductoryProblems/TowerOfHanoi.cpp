#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

void hanoi(int n, int from, int to, int aux) {
  if (n == 0) {
    return;
  }
  hanoi(n - 1, from, aux, to);
  cout << from << " " << to << nl;
  hanoi(n-1, aux, to, from);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int moves = 1;
    for (int i = 0; i < n; i++) {
      moves *= 2;
    }
    cout << --moves << nl;
    hanoi(n, 1, 3, 2);

    return 0;
}