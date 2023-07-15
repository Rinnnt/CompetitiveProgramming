#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string p;
    cin >> p;
    int n;
    cin >> n;
    vector<int> a(n);
    string nums;
    cin >> nums;
    int prev = 0;
    int next = 0;
    for (int i = 0; i < n - 1; i++) {
      while (nums[next] != ',') {
        next++;
      }
      a[i] = stoi(nums.substr(prev + 1, next - prev - 1));
      prev = next;
      next++;
    }
    if (n > 0) {
      next = nums.size() - 1;
      a[n - 1] = stoi(nums.substr(prev + 1, next - prev - 1));
    }

    int l = 0;
    int r = n - 1;
    bool rev = false;
    for (auto c : p) {
      if (c == 'R') {
        rev = !rev;
      } else {
        if (rev) {
          r--;
        } else {
          l++;
        }
      }
    }

    if (l <= r + 1) {
      cout << '[';
      if (rev) {
        if (l <= r) {
          cout << a[r];
        }
        for (int i = r - 1; i >= l; i--) {
          cout << "," << a[i];
        }
      } else {
        if (l <= r) {
          cout << a[l];
        }
        for (int i = l + 1; i <= r; i++) {
          cout << "," << a[i];
        }
      }
      cout << ']';
    } else {
      cout << "error";
    }
    cout << nl;
  }


  return 0;
}
