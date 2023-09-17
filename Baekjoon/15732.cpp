#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int n, k, d;
tuple<int, int, int> rules[10001];

bool usedall(int mid) {
  ll sum = 0;
  for (int i = 0; i < k; i++) {
    int a = get<0>(rules[i]);
    int b = get<1>(rules[i]);
    int c = get<2>(rules[i]);
    int h = min(mid, b);
    if (h >= a) {
      sum += (h - a) / c + 1;
    }
  }
  return sum >= d;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k >> d;
  for (int i = 0; i < k; i++) {
    cin >> get<0>(rules[i]) >> get<1>(rules[i]) >> get<2>(rules[i]);
  }

  int l = -1;
  int r = 1000001;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (usedall(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << r;

  return 0;
}
