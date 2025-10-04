
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
#define N 600005
#define M 305
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
ll fac[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
ll comb(int x, int y) {
  if (x < y) return 0;
  ll y2 = getpw(fac[y], mod2-2) * getpw(fac[x-y], mod2-2) % mod2;
  ll res= fac[x] * y2 % mod2;
  return res;
}
int main() {
 // freopen("data.txt", "r", stdin);
 fac[0]=1LL;
 for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod2;
 }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += a[i];
    }
    if (tot != n) {
      puts("0");
      continue;
    }
    ll ans=0LL;
    bool ok=true;
    for (int i = n; i> (n+1)/2; --i) {
      if (a[i] != 0) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("0");
      continue;
    }
    int cur = 2;
    if (n%2) cur=1;
    ans=1LL;
    int pre=0;
    for (int i = (n+1)/2; i >= 1; --i) {
      int dt = cur-pre;
      ans = ans * comb(dt, a[i]) % mod2;
      cur += 2;
      pre += a[i];
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
