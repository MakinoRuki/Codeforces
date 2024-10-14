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
#define N 500005
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
int sum[N][2];
vector<int> edges[N];
int dfs(int u, int p, int d) {
  sum[d][0]++;
  int mx=d;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    mx = max(mx, dfs(v, u, d+1));
  }
  sum[mx][1]++;
  return mx;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
      sum[i][0] = sum[i][1] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (int i = n-1; i >= 0; --i) {
      sum[i][0] += sum[i+1][0];
    }
    for (int i = 1; i <= n; ++i) {
      sum[i][1] += sum[i-1][1];
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
      int res = 0;
      if (i-1>=0) res += sum[i-1][1];
      if (i+1<=n) res += sum[i+1][0];
      ans = min(ans, res);
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

