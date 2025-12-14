
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
#include <chrono>
#define N 500005
#define M 8002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
ll a[N];
vector<int> edges[N];
map<ll,ll> pre[N];
ll dp[N];
int deg[N];
map<ll, int> cnt;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      edges[i].clear();
      pre[i].clear();
      deg[i]=0;
      dp[i]=0LL;
      cnt[a[i]]++;
    }
    ll ans=0LL;
    for (int i = 1; i <= m; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      pre[v][a[u]] = (pre[v][a[u]]+1)% mod2;
      dp[v] = (dp[v]+1)% mod2;
      deg[v]++;
    }
    vector<pair<ll,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end());
    for (auto pr : rk) {
      int u = pr.second;
    //  cout<<"u="<<u<<" "<<dp[u]<<endl;
      for (auto v : edges[u]) {
        if (a[u] == a[v]) continue;
      //  cout<<"v="<<v<<endl;
      //  cout<<"dpv="<<dp[v]<<endl;
        if (!pre[u].empty()) {
          ll dt = a[v]-a[u];
      //    cout<<"dt="<<dt<<endl;
          if (pre[u].find(dt) != pre[u].end()) {
            ll val = pre[u][dt];
        //    cout<<"val="<<val<<endl;
            pre[v][a[u]] = (pre[v][a[u]] + val) % mod2;
            dp[v] = (dp[v] + val) % mod2;
         //   cout<<"dpv2="<<dp[v]<<endl;
          } 
        }
      }
    //  cout<<endl;
    }
    for (int i = 1; i <= n; ++i) {
      ans = (ans + dp[i]) % mod2;
    }
    // queue<int> q;
    // for (int i = 1; i <= n; ++i) {
    //   if (deg[i]==0) {
    //     q.push(i);
    //   }
    // }
    // while(!q.empty()) {
    //   auto u = q.front();
    //   q.pop();
    //   for (auto v : edges[u]) {
    //     pre[v][a[u]] = (pre[v][a[u]] + 1) % mod2;
    //     dp[v] = (dp[v] + 1) % mod2;
    //     if (!pre[u].empty()) {
    //       ll dt = a[v]-a[u];
    //       if (pre[u].find(dt) != pre[u].end()) {
    //         ll val = pre[u][dt];
    //         pre[v][a[u]] = (pre[v][a[u]] + val) % mod2;
    //         dp[v] = (dp[v] + val) % mod2;
    //       } 
    //     }
    //     deg[v]--;
    //     if (deg[v] == 0) {
    //       ans = (ans + dp[v]) % mod2;
    //       q.push(v);
    //     }
    //   }
    // }
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
