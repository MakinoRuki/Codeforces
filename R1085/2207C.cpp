
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
ll a[N];
ll b[N];
bool vis[N];
ll ls[N];
ll rs[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    if (n == 1) {
      printf("%lld\n", h-a[1]);
      continue;
    }
    ls[0]=0LL;
    ll mx = 0LL;
    for (int i = 1; i <= n; ++i) {
      ls[i]=h-a[i];
      mx=a[i];
      for (int j = i-1; j >= 1; --j) {
        mx = max(mx, a[j]);
        ls[i] += h-mx;
      }
    }
    mx=0LL;
    rs[n+1]=0LL;
    for (int i = n; i >= 1; --i) {
      rs[i] = h-a[i];
      mx = a[i];
      for (int j = i+1; j <= n; ++j) {
        mx = max(mx, a[j]);
        rs[i] += h-mx;
      }
    }
    // for (int i= 1; i <= n; ++i) {
    //   cout<<"i="<<i<<" "<<ls[i]<<" "<<rs[i]<<endl;
    // }
   // cout<<"v="<<ls[3]<<" "<<rs[6]<<endl;
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      ll v1 = ls[i]+rs[i]-(h-a[i]);
      ll mx=a[i];
      int id=i;
      for (int j = i+1; j <= n; ++j) {
       // mx=max(mx, a[j]);
        if (a[j] > mx) {
          mx=a[j];
         id=j;
        }
        ll v2 = ls[j]+rs[j]-(h-a[j]);
        ll v3 = ls[id]+rs[id]-(h-a[id]);
        ll dt = j-i-1;
        ans = max(ans, v1+v2-v3);
       // cout<<"ij="<<i<<" "<<j<<" "<<ans<<endl;
      }
    }
  //  cout<<ans<<endl;
    printf("%lld\n", ans);
  }
  return 0;
}

