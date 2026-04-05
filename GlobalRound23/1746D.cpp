
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
#define N 200005
#define M 1005
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
int b[N];
vector<int> edges[N];
vector<pair<int,ll>> dp[N];
ll dfs(int u, ll k) {
  for (auto pr : dp[u]) {
    if (pr.first == k) return pr.second;
  }
  int sz = (int)edges[u].size();
  ll ans = k * (ll)a[u];
  if (sz == 0) {
    return ans;
  }
  if ((k % sz)==0) {
    for (auto v : edges[u]) {
      ans += dfs(v, k/sz);
    }
  } else {
    int r = k%sz;
    vector<ll> rk;
    rk.clear();
    for (auto v : edges[u]) {
      ll vv = dfs(v, k/sz);
      ans += vv;
      rk.push_back(dfs(v, k/sz+1)-vv);
    }
    sort(rk.begin(), rk.end());
    for (int i = sz-1; i >= sz-r; --i) {
      ans += rk[i];
    }
  }
  dp[u].push_back(make_pair(k, ans));
  return ans;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i =1; i <= n; ++i) {
      edges[i].clear();
      dp[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
      int p;
      scanf("%d", &p);
      edges[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll ans = dfs(1, k);
    printf("%lld\n", ans);
  }
  return 0;
}
