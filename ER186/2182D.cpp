
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
#define M 10002
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
int a[M];
int b[M];
ll fac[60];
ll fac2[60];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
ll comb(ll x, ll y) {
  if (x < y) return 0LL;
  if (x == y) return 1LL;
 // cout<<"xy="<<x<<" "<<y<<endl;
  ll res=fac[x] * fac2[y] % mod2 * fac2[x-y] % mod2;
  return res;
}
int main() {
  fac[0]=1LL;
  fac2[0]=1LL;
  for (int i = 1; i <= 50; ++i) {
    fac[i] = fac[i-1]*(ll)i % mod2;
    fac2[i] = getpw(fac[i], mod2-2) % mod2;
  }

  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int tot =0;
    for (int i =0; i<=n; ++i) {
      scanf("%d", &a[i]);
      tot += a[i];
    }
    int q = tot/n;
    int r = tot%n;
    int cnt1=0,cnt2=0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > q+1) cnt1++;
      else if (a[i] == q+1) cnt2++;
    }
    if (cnt1) {
      puts("0");
      continue;
    }
    if (cnt2 > r) {
      puts("0");
      continue;
    }
    int dt = r-cnt2;
    //cout<<"dt="<<dt<<endl;
    //ll ans=0LL;
    ll ans = comb(n-cnt2, r-cnt2) * fac[r] % mod2 * fac[n-r] % mod2;
    printf("%lld\n", ans);
    //cout<<"???"<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
