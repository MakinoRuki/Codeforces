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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, q, k;
int t;
int p[N];
int bit[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d", &n, &m);
    
  // }
  cin>>n>>k;
  set<int> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    ss.insert(i);
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &p[i]);
    ss.erase(p[i]);
  }
  int cur = k+1;
  vector<int> rk;
  for (int i = k; i >= 1; --i) {
    rk.clear();
    while(!ss.empty() && (*ss.begin()) < p[i]) {
      rk.push_back(*ss.begin());
      ss.erase(*ss.begin());
    }
    for (int j = rk.size()-1; j >= 0; --j) {
      p[cur++] = rk[j];
    }
  }
  rk.clear();
  while(!ss.empty()) {
    auto itr= ss.begin();
    rk.push_back(*itr);
    ss.erase(itr);
  }
  for (int i = rk.size()-1; i >= 0; --i) {
    p[cur++] = rk[i];
  }
  // for (int i= 1; i <= n; ++i) {
  //   cout<<p[i]<<" ";
  // }
  // cout<<endl;
  vector<int> stk;
  stk.clear();
  cur = 1;
  for (int i = 1; i <= n; ++i) {
    while(!stk.empty() && stk.back() == cur) {
      stk.pop_back();
      cur++;
    }
    stk.push_back(p[i]);
  }
  while(!stk.empty() && stk.back() == cur) {
    stk.pop_back();
    cur++;
  }
  if (stk.empty() && cur > n) {
    for (int i = 1; i <= n; ++i) {
      printf("%d", p[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  } else {
    puts("-1");
  }
  return 0;
}
