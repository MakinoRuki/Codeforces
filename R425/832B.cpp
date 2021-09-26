#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 30
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll n, k;
bool gd[M];
bool checkg(string s1, string s2) {
  if (s1.size() != s2.size()) {
    return false;
  }
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] == '?') {
      if (!gd[s2[i]-'a']) {
        return false;
      }
    } else {
      if (s1[i] != s2[i]) {
        return false;
      }
    }
  }
  return true;
}
bool checkb(string s) {
  for (int i = 0; i < s.size(); ++i) {
    if (gd[s[i]-'a']) {
      return false;
    }
  }
  return true;
}
int main() {
  memset(gd, false, sizeof(gd));
  string s;
  cin>>s;
  for (int i = 0; i < s.size(); ++i) {
    gd[s[i]-'a'] = true;
  }
  cin>>s;
  n = (int)s.size();
  vector<string> v;
  v.clear();
  int id = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      id = i;
      break;
    }
  }
  if (id >= 0) {
    v.push_back(s.substr(0, id));
    if (id + 1 < s.size()) v.push_back(s.substr(id+1));
  } else {
    v.push_back(s);
  }
  int m;
  cin>>m;
  while(m-->0) {
    string q;
    cin>>q;
    if (id >= 0) {
      int sz = (int)s.size();
      if (q.size() < sz-1) {
        puts("NO");
        continue;
      }
      if (!checkg(s.substr(0, id), q.substr(0, id))) {
        puts("NO");
        continue;
      }
      int len = sz-1-id;
      if (q.size()-len < q.size() && !checkg(s.substr(id+1), q.substr(q.size()-len))) {
        puts("NO");
        continue;
      }
      if (q.size() == sz-1) {
        puts("YES");
      } else if (!checkb(q.substr(id, q.size()-(sz-1)))) {
        puts("NO");
      } else {
        puts("YES");
      }
    } else if (!checkg(s, q)) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
  return 0;
}
