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
vector<int> a[N];
vector<pair<int,int>> edges[N];
int dp[N];
bool vis[N];
int gett(int x, int cur) {
    int l = 0, r = a[x].size();
    while(l < r) {
        int mid=(l+r)/2;
        if (a[x][mid] > cur) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    if (r >= a[x].size()) return inf;
    return a[x][r];
}
int main() {
  cin>>n>>t;
  for (int i = 1; i <= t; ++i) {
      scanf("%d", &m);
      for (int j = 1; j <= m; ++j) {
          int u,v;
          scanf("%d%d", &u, &v);
          edges[u].push_back(make_pair(v, i));
          edges[v].push_back(make_pair(u, i));
      }
  }
  for (int i = 1; i <= n; ++i) {
      dp[i] = inf;
      vis[i]=false;
  }
  cin>>k;
  int cur=0;
  for (int i = 1; i <= k; ++i) {
      int x;
      scanf("%d", &x);
      a[x].push_back(i);
      if (i == 1) cur = x;
  }
  dp[1] = 1;
  queue<int> q;
  q.push(1);
  vis[1]=true;
  for (int i = 0; i < edges[1].size(); ++i) {
      int v = edges[1][i].first;
      int tm = edges[1][i].second;
     // cout<<"v="<<v<<" "<<tm<<endl;
      if (tm == cur) {
          if (dp[v] >= inf) {
              dp[v] = 1;
              if (!vis[v]) {
                  vis[v] = true;
                  q.push(v);
              }
          }
      }
  }
  while(!q.empty()) {
      int u = q.front();
      q.pop();
      int tu=dp[u];
      vis[u]=false;
      for (int i = 0; i < edges[u].size(); ++i) {
          int v = edges[u][i].first;
          int tt = edges[u][i].second;
          int tv = gett(tt, tu);
          if (tv < inf) {
              if (dp[v] > tv) {
                  dp[v] = tv;
                  if (!vis[v]) {
                      q.push(v);
                      vis[v]=true;
                  }
              }
          }
      }
  }
  if (dp[n] >= inf) {
      puts("-1");
  } else {
      printf("%d\n", dp[n]);
  }
  return 0;
}
