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
#define N 100005
#define M 325
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
int p[N];
ll dp[N][M];
vector<int> edges[N];
int dep[N];
int cnt[N];
int idx[N];
void dfs(int u, int d) {
  dep[u] = d;
  cnt[dep[u]]++;
  idx[u] = cnt[dep[u]];
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    dfs(v, d+1);
  }
}
ll solve(int x, int y) {
  if (!x && !y) return 0;
  if (cnt[dep[x]] <= 320) {
    if (dp[x][idx[y]] >= 0) {
      return dp[x][idx[y]];
    }
    return dp[x][idx[y]] = solve(p[x], p[y]) + (ll)a[x] * (ll)a[y];
  }
  return solve(p[x], p[y]) + (ll)a[x] * (ll)a[y];
}
int main() {
  cin>>n>>q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    edges[i].clear();
  }
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &p[i]);
    edges[p[i]].push_back(i);
  }
  memset(cnt,0,sizeof(cnt));
  dfs(1, 0);
  memset(dp, -1, sizeof(dp));
  while(q-->0) {
    int x,y;
    scanf("%d%d", &x, &y);
    ll ans = solve(x, y);
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

