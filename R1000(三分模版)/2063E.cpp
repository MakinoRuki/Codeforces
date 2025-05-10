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
#define M 1002
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
int a[N];
vector<int> edges[N];
int dep[N];
int cnt[N];
int sum[N];
int par[N];
void dfs(int u, int p, int d) {
  par[u]=p;
  dep[u]=d;
  cnt[u]=1;
  sum[dep[u]]++;
  for (auto v : edges[u]) {
    if (v==p) continue;
    dfs(v, u, d+1);
    cnt[u] += cnt[v];
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    for (int i = 0; i <= n; ++i) {
      sum[i] = 0;
    }
    dfs(1, 0, 0);
    for (int i = n-1; i >= 0; --i) {
      sum[i] += sum[i+1];
    }
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
    //  cout<<"ii="<<i<<" "<<dep[i]<<" "<<sum[dep[i]]<<" "<<cnt[i]<<endl;
      ans += (ll)dep[i] * (ll)(sum[dep[i]]-cnt[i]);
    }
    for (int i = 0; i < n; ++i) {
      ll num = sum[i]-sum[i+1];
      if (num) {
        ll dt = num*(num-1)/2LL;
        ans -= dt*(ll)i;
      }
    }
    ans *= 2LL;
  //  cout<<"ans="<<ans<<endl;
    for (int i = 1; i <= n; ++i) {
      ll cur = cnt[i]-1;
      ll tmp=0LL;
      for (auto p : edges[i]) {
        if (p==par[i]) continue;
        tmp += (ll)cnt[p]*(ll)(cur-cnt[p]);
      }
      tmp/=2LL;
     // cout<<"i="<<i<<" "<<tmp<<endl;
      ans -= (2LL*dep[i]+1)*tmp;
    }
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
