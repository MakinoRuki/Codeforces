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
#define M 52
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  scanf("%d", &n);
  string s;
  cin>>s;
  set<int> dp, rp;
  dp.clear();
  rp.clear();
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      rp.insert(i);
    } else {
      dp.insert(i);
    }
  }
  int cur=0;
  while(dp.size() + rp.size() > 1) {
    if (s[cur] == 'D') {
      if (rp.empty()) {
        break;
      }
      auto itr = rp.upper_bound(cur);
      if (itr == rp.end()) {
        itr = rp.begin();
      }
      rp.erase(*itr);
    } else {
      if (dp.empty()) {
        break;
      }
      auto itr = dp.upper_bound(cur);
      if (itr == dp.end()) {
        itr = dp.begin();
      }
      dp.erase(*itr);
    }
    if (rp.empty() || dp.empty()) {
      break;
    }
    auto itr1 = dp.upper_bound(cur);
    auto itr2 = rp.upper_bound(cur);
    if (itr1 == dp.end()) {
      itr1 = dp.begin();
    }
    if (itr2 == rp.end()) {
      itr2 = rp.begin();
    }
    if ((*itr1) == cur) {
      cur = (*itr2);
      continue;
    }
    if ((*itr2) == cur) {
      cur = (*itr1);
      continue;
    }
    if (((*itr1) > cur && (*itr2) > cur) || ((*itr1) < cur && (*itr2) < cur)) {
      cur = min((*itr1), (*itr2));
    } else {
      cur = max((*itr1), (*itr2));
    }
  }
  if (dp.empty()) {
    puts("R");
  } else {
    puts("D");
  }
  return 0;
}
