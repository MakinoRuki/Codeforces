#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 3000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int d[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  cin>>n;
  a[0]=0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    d[i] = a[i]-a[i-1];
  }
  vector<pair<int,int>> ans;
  ans.clear();
  vector<int> stk;
  stk.clear();
  for (int i = 1; i <= n; ++i) {
    if (d[i] > 0) {
      stk.push_back(i);
    } else if (d[i] < 0) {
      int dt = -d[i];
      while(dt) {
        int id = stk.back();
        int tmp=min(dt, d[id]);
        for (int j = 1; j <= tmp; ++j) {
          ans.push_back(make_pair(id, i-1));
        }
        d[id] -= tmp;
        dt -= tmp;
        if (d[id] == 0) stk.pop_back();
      }
    }
  }
  while(!stk.empty()) {
    int id = stk.back();
    for (int i = 1; i <= d[id]; ++i) {
      ans.push_back(make_pair(id, n));
    }
    stk.pop_back();
  }
  printf("%d\n", (int)ans.size());
  for (auto pr : ans) {
    printf("%d %d\n", pr.first, pr.second);
  }
  return 0;
}
 
