#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;
  deque<string> vars;
  deque<string> ops;
  map<string, int> precedence = {
    {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"(", 0}, {")", -1}
  };

  for (int i = 0; i < s.size(); i++) {
    string c = s.substr(i, 1);
    if (precedence.count(c)) {
      int p = precedence[c];
      if (c == "(" || ops.empty() || precedence[ops.back()] < p) {
        ops.push_back(c);
      } else {
        while (!ops.empty() && precedence[ops.back()] >= p) {
          string op = ops.back();
          ops.pop_back();
          if (op == "(") {
            break;
          } else {
            string second = vars.back();
            vars.pop_back();
            string first = vars.back();
            vars.pop_back();
            vars.push_back(first + second + op);
          }
        }
        if (c != ")") {
          ops.push_back(c);
        }
      }
    } else {
      vars.push_back(c);
    }
  }

  while (!ops.empty()) {
    string op = ops.back();
    ops.pop_back();
    string second = vars.back();
    vars.pop_back();
    string first = vars.back();
    vars.pop_back();
    vars.push_back(first + second + op);
  }

  if (vars.empty()) {
    cout << "";
  } else {
    cout << vars.back();
  }

  return 0;
}
