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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int cnt[N];
ll sum[N][5];
ll tot;
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
void dfs(int u, int p) {
  cnt[u] = 1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if ( v== p) continue;
    dfs(v, u);
    cnt[u] += cnt[v];
  }
  ll cur=(cnt[u] >= k ? sum[cnt[u]][k] : 0);
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    if (cnt[v] >= k) {
      cur = (cur - sum[cnt[v]][k] + mod) % mod;
    }
  }
  if (k == 2) {
    cur = (cur + (ll)cnt[u] * (ll)(n-cnt[u]) % mod) % mod;
  } else {
    ll dt = 0LL;
    if (n-cnt[u] >= 2) dt = (dt + (ll)cnt[u] * sum[n-cnt[u]][2] % mod) % mod;
    if (cnt[u] >= 2) dt = (dt + (ll)(n-cnt[u]) * sum[cnt[u]][2] % mod) % mod; 
    cur = (cur + dt) % mod;
  }
  tot = (tot + cur) % mod;
}
int main() {
  cin>>n>>k;
  for (int i = 1; i <= n; ++i) {
    edges[i].clear();
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  if ( k == 1 || k==3) {
    puts("1");
    return 0;
  }
  memset(sum, 0LL, sizeof(sum));
  for (int i = 2; i <= n; ++i) {
    sum[i][2] = (ll)i*(ll)(i-1)/2LL;
    sum[i][2] %= mod;
    if (i >= 3) {
      sum[i][3] = (ll)i*(ll)(i-1)*(ll)(i-2)/6LL;
      sum[i][3] %= mod;
    }
  }
  tot = 0LL;
  dfs(1, 0);
  tot = tot * getpw(sum[n][2], mod-2) % mod;
  printf("%lld\n", tot);
  return 0;
}
