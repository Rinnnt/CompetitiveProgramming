#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, r, c;
  cin >> N >> r >> c;
  int ans = 0;
  while (N) {
    int mid = 1 << (N - 1);
    int sq = mid * mid;
    if (r < mid && c < mid) {
      ans += 0 * sq;
    } else if (r < mid && c >= mid) {
      ans += 1 * sq;
      c -= mid;
    } else if (r >= mid && c < mid) {
      ans += 2 * sq;
      r -= mid;
    } else {
      ans += 3 * sq;
      r -= mid;
      c -= mid;
    }
    N--;
  }
  cout << ans;

}
