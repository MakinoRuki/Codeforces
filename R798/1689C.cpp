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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int dp[N];
int cnt[N];
void dfs1(int u, int p) {
  cnt[u] = 1;
  int num=(int)edges[u].size();
  vector<int> ids;
  ids.clear();
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v==p) continue;
    dfs1(v, u);
    cnt[u] += cnt[v];
    ids.push_back(v);
  }
  if (ids.empty()) {
    dp[u] = 0;
    return;
  }
  if (ids.size() == 1) {
    dp[u] = cnt[ids[0]]-1;
    return;
  }
  dp[u] = max(cnt[ids[0]]-1+dp[ids[1]], cnt[ids[1]]-1+dp[ids[0]]);
  return ;
}
void dfs2(int u, int p, int& tot) {
  vector<int> ids;
  ids.clear();
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v==p) continue;
    ids.push_back(v);
  }
  if (ids.empty()) {
    return;
  }
  if (ids.size() == 1) {
    tot += cnt[ids[0]]-1;
  } else {
    if (cnt[ids[0]]-1+dp[ids[1]] > cnt[ids[1]]-1+dp[ids[0]]) {
      tot += cnt[ids[0]]-1;
      dfs2(ids[1], u, tot);
    } else {
      tot += cnt[ids[1]]-1;
      dfs2(ids[0], u, tot);
    }
  }
}
int main() {
  cin>>t;
//  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i =1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    dfs1(1, 0);
    // for (int i = 1; i <= n; ++i) {
    //   cout<<"i="<<i<<" "<<cnt[i]<<" "<<dp[i]<<endl;
    // }
    int tot=0;
    dfs2(1, 0, tot);
    printf("%d\n", tot);
  }
  return 0;
}
