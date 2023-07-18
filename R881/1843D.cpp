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
#define N 600005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
vector<int> edges[N];
int cnt[N];
void dfs(int u, int p) {
  bool found=false;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    found=true;
    dfs(v, u);
    cnt[u] += cnt[v];
  }
  if (!found) cnt[u] = 1;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      cnt[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    dfs(1, 0);
    scanf("%d", &q);
    while(q-->0) {
      int x,y;
      scanf("%d%d", &x, &y);
     // cout<<"cntx="<<cnt[x]<<" "<<"cnty="<<cnt[y]<<endl;
      ll ans = (ll)cnt[x] * (ll)cnt[y];
      printf("%lld\n", ans);
    }
  }
  return 0;
}
