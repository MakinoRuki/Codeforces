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
vector<pair<int,int>> edges[N];
ll dp[N][2];
ll sum[N];
bool vis[N];
void dfs(int u) {
  vis[u]=true;
  for (auto pr : edges[u]) {
    int v = pr.first;
    int w = pr.second;
    //if ()
    if (!vis[v]) {
      dfs(v);
    }
    sum[u] = (sum[u] + sum[v]) % mod2;
    if (w) sum[u] = (sum[u] + dp[v][0])%mod2;
    else sum[u] = (sum[u] + dp[u][1]) % mod2;
    sum[u] = (sum[u] + (dp[u][1] * dp[v][0] % mod2)%mod2) % mod2;
    dp[u][1] = (dp[u][1] + dp[v][1]) % mod2;
    dp[u][0] = (dp[u][0] + dp[v][0]) % mod2;
    if (w) dp[u][1] = (dp[u][1]+1) % mod2;
    else dp[u][0] = (dp[u][0]+1) % mod2;
   // cout<<"u="<<u<<" "<<v<<" "<<sum[u]<<endl;
  }
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
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    edges[i].clear();
  }
  for (int i = 1; i <= n; ++i) {
    int l;
    scanf("%d", &l);
    for (int j =1; j <= l; ++j) {
      int u, w;
      scanf("%d%d", &u, &w);
      edges[i].push_back(make_pair(u, w));
    }
  }
  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(sum));
  dfs(1);
  printf("%lld\n", sum[1]);
  return 0;
}
