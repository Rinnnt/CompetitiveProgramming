#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

ll nums[500001];
ll t[4 * 500001];
ll tmp[500001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = 0;
    return;
  }

  int mid = (tl + tr) / 2;
  t[ti] = 0;

  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti] += t[ti * 2 + 1];
  t[ti] += t[ti * 2 + 2];

  int i = tl;
  int j = mid + 1;
  int k = tl;
  while (i <= mid && j <= tr) {
    if (nums[i] > nums[j]) {
      tmp[k++] = nums[j++];
      t[ti] += mid - i + 1;
    } else {
      tmp[k++] = nums[i++];
    }
  }

  while (i <= mid)
    tmp[k++] = nums[i++];

  while (j <= tr)
    tmp[k++] = nums[j++];

  for (int i = tl; i <= tr; i++)
    nums[i] = tmp[i];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  build(0, 0, n - 1);

  cout << t[0] << nl;

  return 0;
}

