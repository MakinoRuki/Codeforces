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
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
ll p[N];
ll p2[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
ll comb(int x, int y) {
  if (x < 0 || y < 0 || x < y) return 0LL;
  ll res = p[x] * p2[y] % mod * p2[x-y] % mod;
  return res;
}
int main() {
  p[0] = 1LL;
  p2[0] = getpw(p[0], mod-2);
  for (int i = 1; i < N; ++i) {
    p[i] = p[i-1] * (ll)i % mod;
    p2[i] = getpw(p[i], mod-2);
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int m1,m2;
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= m1; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m2; ++i) {
      scanf("%d", &b[i]);
    }
    if (a[m1] != b[1]) {
      puts("0");
      continue;
    }
    if (a[1] != 1 || b[m2] != n) {
      puts("0");
      continue;
    }

    ll ans = comb(n-1, a[m1]-1);
   // cout<<"ans1="<<ans<<" "<<comb(3,1)<<endl;
    for (int i = m1-1; i >= 1; --i) {
      ans = ans * comb(a[i+1]-2, a[i+1]-a[i]-1) % mod * p[a[i+1]-a[i]-1] % mod;
    }
    //cout<<"ans2="<<ans<<endl;
    for (int i = 2; i <= m2; ++i) {
      ans = ans * comb(n-b[i-1]-1, b[i]-b[i-1]-1) % mod * p[b[i]-b[i-1]-1] % mod;
    }
    ll tmp = comb(19, 11) * comb(10, 7) % mod * comb(2, 0)*comb(1,0)*comb(0,0)%mod*comb(7,0)*comb(6,4)*comb(1,1)%mod;
   // cout<<"tmp="<<tmp<<endl;
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

