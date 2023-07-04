#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class CirclesCountry {
public:
  int leastBorders(vector<int> X, vector<int> Y, vector<int> R, int x1, int y1, int x2, int y2) {
    int res = 0;
    for (int i = 0; i < X.size(); i++) {
      if ((((x1 - X[i]) * (x1 - X[i]) + (y1 - Y[i]) * (y1 - Y[i]) <= R[i] * R[i]) && !((x2 - X[i]) * (x2 - X[i]) + (y2 - Y[i]) * (y2 - Y[i]) <= R[i] * R[i]))
          || (!((x1 - X[i]) * (x1 - X[i]) + (y1 - Y[i]) * (y1 - Y[i]) <= R[i] * R[i]) && ((x2 - X[i]) * (x2 - X[i]) + (y2 - Y[i]) * (y2 - Y[i]) <= R[i] * R[i]))) {
        res++;
      }
    }

    return res;
  }
};