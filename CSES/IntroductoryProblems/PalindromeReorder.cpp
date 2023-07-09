#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    map<char, int> chars;
    for (char c : s) {
      chars[c]++;
    }

    int odd = 0;
    char oddchar = '#';
    map<char, int>::iterator it;
    for (it = chars.begin(); it != chars.end(); it++) {
      if (it->second % 2) {
        oddchar = it->first;
        odd++;
      }
    }

    if (odd > 1) {
      cout << "NO SOLUTION";
    } else {
      string res;
      map<char, int>::iterator it;
      for (it = chars.begin(); it != chars.end(); it++) {
        for (int i = 0; i < it->second / 2; i++) {
          res += it->first;
        }
      }
      
      for (int i = 0; i < res.size(); i++) {
        cout << res[i];
      }
      if (oddchar != '#') {
        cout << oddchar;
      }
      for (int i = res.size() - 1; i >=0; i--) {
        cout << res[i];
      }
    }

    return 0;
}