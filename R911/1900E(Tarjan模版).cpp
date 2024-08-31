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
#include <stack>
#define N 300005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int dp[N],sz[N];
ll mn[N],sum[N];

int dfn[N],low[N],col[N],ccnt,dcnt;
bool vis[N];
stack<int> stk;
vector<int> p[N];
void tarjan(int u) {
    stk.push(u); dfn[u]=low[u]=++dcnt; vis[u]=true;
    for(auto v:edges[u]) {
        if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]) {
        col[u]=++ccnt,sum[ccnt]=a[u],p[ccnt].emplace_back(u); vis[u]=false;
        while(!stk.empty()&&stk.top()!=u) {
            col[stk.top()]=ccnt,sum[ccnt]+=a[stk.top()],p[ccnt].emplace_back(stk.top());
            vis[stk.top()]=false,stk.pop();
        }
        sz[ccnt]=p[ccnt].size();
        stk.pop();
    }
}

int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      edges[i].clear();
      dfn[i] = 0;
      low[i] = 0;
      col[i] = 0;
      p[i].clear();
    }
    ccnt = 0;
    dcnt = 0;
    for (int i = 1; i <= m; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
    }
    // Tarjan求SCC模版
    for (int i = 1; i <= n; ++i) {
      if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= ccnt; ++i) {
      dp[i] = 0, mn[i] = (1LL<<61)-1;
      for (auto u : p[i]) {
        for (auto v : edges[u]) {
          if (col[u] == col[v]) continue;
          if (dp[col[v]] > dp[col[u]]) {
            dp[col[u]] = dp[col[v]], mn[col[u]] = mn[col[v]];
          } else if (dp[col[v]] == dp[col[u]]) {
            mn[col[u]] = min(mn[col[u]], mn[col[v]]);
          }
        }
      }
      dp[i] += sz[i];
      if (mn[i] >= (1LL<<61)-1) {
        mn[i] = sum[i];
      } else {
        mn[i] += sum[i];
      }
    }
    ll ans0 = 0LL, ans1 = (1LL<<61)-1;
    for (int i = 1; i <= ccnt; ++i) {
      if (dp[i] > ans0) {
        ans0 = dp[i];
        ans1 = mn[i];
      } else if (dp[i] == ans0) {
        ans1 = min(ans1, mn[i]);
      }
    }
    printf("%lld %lld\n", ans0, ans1);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
 
