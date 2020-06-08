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
#define N 100002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, k;
vector<int> edges[N];
bool vis[N];
int cnt;
void dfs(int u, int p) {
  vis[u] = true;
  cnt++;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    if (!vis[v]) {
      dfs(v, u);
    }
  }
}
ll getpw(ll a, ll b) {
  ll res=1LL;
  while(b) {
    if (b&1) res=res*a%mod;
    a = a*a%mod;
    b /= 2;
  }
  return res;
}
int main() {
  cin>>n>>k;
  for (int i = 1; i < n; ++i) {
    int u, v, x;
    scanf("%d%d%d", &u, &v, &x);
    if (!x) {
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
  }
  memset(vis, false, sizeof(vis));
  ll ans=1LL;
  for (int i = 1; i <= k; ++i) {
    ans = ans*(ll)n % mod;
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      cnt=0;
      dfs(i, 0);
      ll res = getpw(cnt, k);
      ans = (ans - res + mod) % mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}
