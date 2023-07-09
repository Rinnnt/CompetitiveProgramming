#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class CantorDust {
public:
  string getString(int T) {
    if (T == 0) {
      return "X";
    }
    string c = getString(T - 1);
    return c + string(c.size(), ' ') + c;
  }

  int occurrencesNumber(vector<string> pattern, int time) {
    int M = pattern.size(), N = pattern[0].size();
    vector<bool> a(M), b(N);
    for (int i = 0; i < M; i++) a[i] = false;
    for (int i = 0; i < N; i++) b[i] = false;
    string C = getString(time);
    int L = C.size();
    int x, y, k;
    int p = 0, q = 0;
    bool flag = false;
    for (x = 0; x < M; ++x)
      for (y = 0; y < N; ++y)
        if (pattern[x][y] == 'X')
          a[x] = b[y] = flag = true;
    for (x = 0; x < M; ++x)
      for (y = 0; y < N; ++y)
        if ((pattern[x][y] == 'X') != (a[x] && b[y])) return 0;
    
    for (k = 0; k + M <= L; ++k) {
      for (x = 0; x < M; ++x)
        if ((C[k + x] == 'X') != a[x]) break;
      if (x == M) ++p;
    }

    for (k = 0; k + N <= L; ++k) {
      for (y = 0; y < M; ++y)
        if ((C[k + y] == 'X') != b[y]) break;
      if (y == N) ++q;
    }

    if (flag) return p * q;
    else return (p * (L - N + 1) + (L - M + 1) * q - p * q);
  }
};