#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool visited[50];

class HamiltonPath {
public:
  vector<string> roads;
  int count(string s, char c) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == c) {
        res++;
      }
    }
    return res;
  }

  int countPaths(vector<string> roads) {
    this->roads = roads;
    for (int i = 0; i < 50; i++) {
      visited[i] = false;
    }

    int free = 0;
    int links = 0;
    for (int i = 0; i < roads.size(); i++) {
      int ys = count(roads[i], 'Y');
      if (ys == 0) {
        visited[i] = true;
        free++;
      } else if (ys == 1 && !visited[i]) {
        links++;
        dfs(i);
      } else if (ys > 2){
        return 0;
      }
    }

    ll paths = 1;
    for (int i = 0; i < roads.size(); i++) {
      if (!visited[i]) {
        return 0;
      }
    }
    for (int i = 2; i <= free + links; i++) {
      paths = (paths * i) % 1000000007;
    }
    for (int i = 0; i < links; i++) {
      paths = (paths * 2) % 1000000007;
    }

    return (int)paths;
  }

  void dfs(int city) {
    visited[city] = true;
    for (int i = 0; i < roads[city].size(); i++) {
      if (roads[city].substr(i, 1) == "Y" && !visited[i]) {
        dfs(i);
      }
    }
  }
};