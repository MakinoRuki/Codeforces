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
#define M 200
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
string s;
vector<string> ts;
vector<vector<string>> ans;
void dfs(int& id, int lv) {
  if (id >= ts.size()) return;
  if (lv >= ans.size()) {
    ans.push_back({});
  }
  ans[lv].push_back(ts[id]);
  id++;
  int cnt = stoi(ts[id]);
  id++;
  for (int i = 0; i < cnt; ++i) {
    dfs(id, lv+1);
  }
}
int main() {
  cin>>s;
  ts.clear();
  string tmp="";
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ',') {
      ts.push_back(tmp);
      tmp.clear();
    } else {
      tmp.push_back(s[i]);
    }
  }
  if (!tmp.empty()) {
    ts.push_back(tmp);
  }
  ans.clear();
  int i = 0;
  while(i < ts.size()) {
    dfs(i, 0);
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j) {
      cout<<ans[i][j];
      if (j < ans[i].size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
