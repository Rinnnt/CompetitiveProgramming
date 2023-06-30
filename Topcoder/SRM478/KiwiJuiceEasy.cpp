#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class KiwiJuiceEasy {
  public:
  vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {
    vector<int> res(bottles);

    for (int i = 0; i < fromId.size(); i++) {
      int m = min(res[fromId[i]], capacities[toId[i]] - res[toId[i]]);
      res[fromId[i]] -= m;
      res[toId[i]] += m;
    }

    return res;
  }
};