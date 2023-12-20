#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int a[5][5];
int b[5][5];

int inversions(vector<int> &a) {
  int res = 0;
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++)
      if (a[i] > a[j])
        res++;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> b[i][j];

  vector<int> rs;
  for (int i = 0; i < h; i++)
    rs.push_back(i);

  int ans = 1e9;
  do {

    vector<int> cs;
    for (int i = 0; i < w; i++)
      cs.push_back(i);

    do {
      bool pos = true;
      for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
          if (b[i][j] != a[rs[i]][cs[j]])
            pos = false;

      if (pos)
        ans = min(ans, inversions(rs) + inversions(cs));

    } while (next_permutation(cs.begin(), cs.end()));

  } while (next_permutation(rs.begin(), rs.end()));

  if (ans == 1e9)
    cout << -1 << nl;
  else
    cout << ans << nl;

  return 0;
}

