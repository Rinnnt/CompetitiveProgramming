#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  while (N--) {
    int x; 
    cin >> x;
    if (x) {
      min_heap.push(x);
    } else {
      if (min_heap.empty()) {
        cout << 0 << nl;
      } else {
        cout << min_heap.top() << nl;
        min_heap.pop();
      }
    }
  }

}
