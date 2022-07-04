#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
vector<int> ns[N];
bool vis[N];
int nxt[N];
int dp[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
void extgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  extgcd(b, a%b, x, y);
  ll tx = x;
  x = y;
  y = tx - (a/b) * y;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n>>m;
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    vis[x] = true;
  }
  for (int i = 1; i < m; ++i) {
    if (!vis[i]) {
      int g = getgcd(i, m);
      ns[g].push_back(i);
    }
  }
  memset(dp, -1, sizeof(dp));
  memset(nxt, -1, sizeof(nxt));
  int ans = 0, id = -1;
  for (int i = m-1; i >= 1; --i) {
    if (ns[i].size() > 0) {
      dp[i] = (int)ns[i].size();
      for (int j = 2 * i; j < m; j += i) {
        if (ns[j].size() > 0) {
          if (dp[j] + (int)ns[i].size() > dp[i]) {
            dp[i] = dp[j] + (int)ns[i].size();
            nxt[i] = j;
          }
        }
      }
      if (dp[i] > ans) {
        ans = dp[i];
        id = i;
      }
    }
  }
//  cout<<"ans="<<ans<<" "<<id<<endl;
  vector<int> tmp;
  tmp.clear();
  int cur = id;
  while(cur > 0) {
    for (int i = 0; i < ns[cur].size(); ++i) {
      tmp.push_back(ns[cur][i]);
    }
    cur = nxt[cur];
  }
  vector<int> res;
  res.clear();
  for (int i = 0; i < tmp.size(); ++i) {
  //  cout<<"i="<<i<<" "<<tmp[i]<<endl;
    // if (tmp[i] == 0) {
    //   cout<<"!!!!!"<<"i="<<i<<" "<<tmp[i]<<endl;
    //   return 0;
    // }
    if (i == 0) res.push_back(tmp[i]);
    else {
      ll x, y;
      extgcd(tmp[i-1], m, x, y);
      ll g = getgcd(tmp[i-1], m);
    //  cout<<"x0="<<x<<endl;
    //  cout<<"x1="<<x<<endl;
      x *= (tmp[i]/g);
    //  cout<<"x2="<<x<<endl;
      x = (x % m + m) % m;
      // if (x == 0) {
      //   cout<<"!!!"<<i<<" "<<tmp[i-1]<<" "<<x<<endl;
      //   return 0;
      // }
      res.push_back(x);
    }
  }
  // for (int i = 0; i < res.size(); ++i) {
  //   if (res[i] == 0) {
  //     cout<<"???"<<"i="<<i<<endl;
  //     return 0;
  //   }
  // }
  if (!vis[0]) res.push_back(0);
  printf("%d\n", (int)res.size());
  for (int i = 0; i < res.size(); ++i) {
    printf("%d",res[i]);
    if (i<res.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
