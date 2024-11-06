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
#define N 2000005
#define M 60
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    ll s1=0LL, s2=0LL;
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (i <= k) s1 += a[i];
      else s2 += a[i];
      tot += a[i];
    }
  //  cout<<"tot="<<tot<<endl;
    s1 %= mod;
    s2 %= mod;
    s1 = s1 * getpw(k, mod-2) % mod;
    s2 = s2 * getpw(n-k, mod-2) % mod;
    ll ans=0LL;
    ll n1 = (ll)((n-k)/2+1)*(ll)k%mod;
    n1 = n1 * getpw(n-k+1, mod-2) % mod;
    ans = (ans + n1 * s1 % mod) % mod;
    ll n2 = (n-k+1)/2%mod;
    ans = (ans + n2 * s2 % mod) % mod;
    printf("%lld %lld\n", ans, (tot-ans+mod)%mod);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

