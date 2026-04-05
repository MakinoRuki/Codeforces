/*
经典换根树形dp。以1为根dfs，对于顶点u，先根据u的儿子v们算出u往儿子走的胜负状态dp[u][0]；然后再从上往下dp出u往父亲走的胜负状态dp[u][1]。
比如u往fa[u]=pa走，需要看pa除了u之外的其它儿子的结果和dp[pa][1]的结果，根据这些确定dp[u][1]的结果。
*/

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
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
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
int p[N];
vector<int> edges[N];
int cnt[N][2];
int dp[N][2];
int ans[N];
int dfs(int u, int p) {
  int c0=0,c1=0;
  for (auto v : edges[u]) {
    if (v == p) continue;
    int res=dfs(v, u);
    if (res) c1++;
    else c0++;
  }
  if (c1+c0 == 0) {
    return dp[u][0] = 0;
  }
  cnt[u][0] = c0;
  cnt[u][1] = c1;
  if (c0 == 0) return dp[u][0] = 0;
  return dp[u][0]= 1;
}
void dfs2(int u, int p) {
  if (u != 1) {
    int c0 = cnt[p][0];
    int c1 = cnt[p][1];
    if (dp[u][0]) c1--;
    else c0--;
    if (c0+ c1==0 || !c0) {
      if (p!=1 && dp[p][1]) dp[u][1] = 0;
      else dp[u][1]= 1;
    } else {
      dp[u][1] = 0;
    }
   //if (u == 9) cout<<"c01="<<c0<<" "<<c1<<endl;
  }
  for (auto v : edges[u]) {
    if (v == p) continue;
    dfs2(v, u);
  }
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>n>>q;
  for (int i = 1; i < n; ++i) {
    int u,v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 0);
  // for (int i = 1; i <= n; ++i) {
  //   cout<<"i="<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
  // }
  while(q-->0) {
    int u;
    scanf("%d", &u);
    if (u == 1) {
      if (dp[u][0]) {
        puts("Ron");
      } else {
        puts("Hermione");
      }
    } else {
      if (dp[u][0] || dp[u][1]) puts("Ron");
      else puts("Hermione");
    }
  }
  return 0;
}

