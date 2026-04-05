
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
#define M 505
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
int p[N];
vector<int> edges[N];
//bool vis[N];
int cnt[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      //vis[i]=false;
      cnt[i]=0;
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    ll c1=0,c0=0;
    for (int i = 1; i <= n; ++i) {
      int sz=(int)edges[i].size();
      if (sz == 1) c1++;
      else c0++;
    }
    ll ans = c0*c1;
  //  cout<<"ans="<<ans<<endl;
    c0=0,c1=0;
    ll c01=0;
    for (int i = 1; i <= n; ++i) {
      int sz=(int)edges[i].size();
      if (sz > 1) {
        int n0=0;
        int n1=0;
        for (auto v : edges[i]) {
          int sz2=(int)edges[v].size();
          if (sz2 == 1) {
            n1++;
          } else {
            n0++;
          }
        }
        if (!n1) c0++;
        else {
          cnt[i] = n0;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (cnt[i]) {
        ans += c0 * (ll)(cnt[i]-1);
      }
    }
  //  cout<<c0<<" "<<c1<<" "<<c01<<endl;
    // ans += (c0-c01)*c1+c0*(c1-c01);
    // if (c01>1) ans += c01*(c01-1);
    printf("%lld\n", ans);
  }
  return 0;
}

