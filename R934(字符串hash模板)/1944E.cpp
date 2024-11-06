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
#include <bitset>
#define N 2000005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
vector<int> edges[N];
int dis[N];
int par[N];
void dfs(int u, int p, int d) {
  par[u] = p;
  dis[u] = d;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}
int calc() {
  dfs(1, 0, 0);
  int u=1;
  for (int i = 2; i <= n; ++i) {
    if (dis[i]>dis[u]) {
      u = i;
    }
  }
  dfs(u, 0, 0);
  int v = u;
  for (int i = 1; i <= n; ++i) {
    if (dis[i] > dis[v]) {
      v = i;
    }
  }
  return v;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    int u = calc();
    vector<int> v;
    v.clear();
    while(u) {
      v.push_back(u);
      u = par[u];
    }
    int sz = (int)v.size();
    if (sz % 2) {
      int u = v[sz/2];
      printf("%d\n", sz/2+1);
      for (int i = 0; i <= sz/2; ++i) {
        printf("%d %d\n", u, i);
      }
    } else {
      int u1 = v[sz/2], u2=v[sz/2-1];
      int cnt=0;
      vector<pair<int,int>> ans;
      ans.clear();
      for (int i = 1; i <= sz/2; i+=2) {
        ans.push_back(make_pair(u1, i));
      }
      for (int i = 1; i <= sz/2; i+=2) {
        ans.push_back(make_pair(u2, i));
      }
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first,ans[i].second);
      }
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

