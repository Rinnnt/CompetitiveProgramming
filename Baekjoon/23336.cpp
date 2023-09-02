#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

ll ans = 0;
int a[200001];
int tmp[200001];

void merge_sort(int l, int r) {
  if (l >= r) {
    return;
  }

  int mid = (l + r) / 2;
  merge_sort(l, mid);
  merge_sort(mid + 1, r);

  int ptr1 = l;
  int ptr2 = mid + 1;
  int tmpptr = l;

  while (ptr1 < mid + 1 && ptr2 < r + 1) {
    if (a[ptr1] <= a[ptr2]) {
      tmp[tmpptr++] = a[ptr1++];
    } else {
      tmp[tmpptr++] = a[ptr2++];
      ans += mid + 1 - ptr1;
    }
  }

  while (ptr1 < mid + 1) {
    tmp[tmpptr++] = a[ptr1++];
  }
  while (ptr2 < r + 1) {
    tmp[tmpptr++] = a[ptr2++];
  }

  for (int i = l; i <= r; i++) {
    a[i] = tmp[i];
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x - 1] = i;
    }

    merge_sort(0, n - 1);

    cout << ans;

    return 0;
}
