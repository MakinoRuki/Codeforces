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
#define N 500005
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
ll a[N];
vector<int> edges[N];
int p[N];
ll dp[N];
ll dfs(int u) {
  ll mn=(1LL<<61)-1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    ll res = dfs(v);
    mn = min(mn, res);
  }
  if (mn >= (1LL<<61)-1) {
    return a[u];
  }
  if (u == 1) {
    a[u] += mn;
    return a[u];
  }
  if (a[u] < mn) {
    a[u] = (a[u]+mn)/2;
    return a[u];
  }
  return min(mn, a[u]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      edges[i].clear();
    }
    for (int i= 2; i <= n; ++i) {
      scanf("%d", &p[i]);
      edges[p[i]].push_back(i);
    }
    dfs(1);
    printf("%lld\n", a[1]);
  } 
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

