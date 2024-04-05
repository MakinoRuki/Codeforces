#include <iostream>
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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int bit[N];
int dp[N];
int mx;
int lowbit(int x) {
  return x&(-x);
}
void update(int x, int v, int f) {
  while(x <= mx) {
    if (f) bit[x] = max(bit[x], v);
    else bit[x]=0;
    x += lowbit(x);
  }
}
int query(int x) {
  int res=0;
  while(x) {
    res=max(res, bit[x]);
    x -= lowbit(x);
  }
  return res;
}
int main() {
  cin>>t;
  memset(bit, 0, sizeof(bit));
  memset(dp, 0, sizeof(dp));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,vector<int>>> v;
    v.clear();
    mx=0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &k);
      vector<int> tmp;
      tmp.clear();
      int tmx=0;
      for (int j = 1; j <= k; ++j) {
        int x;
        scanf("%d", &x);
        if (tmp.empty() || x > tmp.back()) {
          mx=max(mx, x);
          tmx=max(tmx, x);
          tmp.push_back(x);
        }
      }
      v.push_back(make_pair(tmx, tmp));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
      auto tmp = v[i].second;
      int tmx = v[i].first;
      int sz = (int)tmp.size();
      for (int j = 0; j < sz; ++j) {
        int res=0;
        if (tmp[j]-1>0) {
          res = query(tmp[j]-1);
        }
     //   cout<<"i="<<i<<" "<<j<<" "<<tmp[j]<<" "<<res<<" "<<tmx<<endl;
        dp[tmx] = max(dp[tmx], res+sz-j);
       // cout<<dp[tmx]<<endl;
      }
      update(tmx, dp[tmx], 1);
    }
    int ans=0;
    for (int i = 0; i < v.size(); ++i) {
      ans = max(ans, dp[v[i].first]);
    }
    for (int i = 0; i < v.size(); ++i) {
      update(v[i].first, 0, 0);
      dp[v[i].first] = 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}
