
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
#define N 21000005
#define M 50
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int fac[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  x %= mod3;
  while(y) {
    if (y&1) res=res*x%mod3;
    x=x*x%mod3;
    y /= 2;
  }
  return res;
}
ll getfac2(ll x) {
  return getpw(fac[x], mod3-2);
}
ll comb(ll x, ll y) {
  if (x < y) return 0LL;
  if (x == y) return 1LL;
  ll res = (ll)fac[x] * getfac2(y) % mod3 * getfac2(x-y) % mod3;
  return res;
}
int main() {
  fac[0]=1LL;
  for (int i = 1; i < N; ++i) {
    fac[i]=(int)((ll)fac[i-1]*(ll)i % mod3);
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int id0=-1,id1=-1;
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i =1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    int mx=21;
    for (int i = 1; i <= n; ++i) {
      int cur=0;
      int x=a[i];
      while(true) {
        if (x*2<=b[i]) {
          cur++;
          x*=2;
        } else {
          break;
        }
      }
      mx = min(mx, cur);
    }
    ll tmp=(1LL<<mx);
    ll ans=1LL;
    ll res=0LL;
    for (int i = 0; i < mx; ++i) {
      ll num=0LL;
      vector<int> v;
      v.clear();
      for (int j = 1; j <= n; ++j) {
        ll dt = b[j]/tmp-a[j];
        num += dt;
        a[j] += dt;
        v.push_back(dt);
        res += dt;
      }
   //   cout<<"i="<<i<<endl;
      ll tot=0LL;
      for (auto x : v) {
        tot += x;
      }
      if (tot >= mod3) {
        ans *= 0LL;
      } else {
        ans = ans * fac[tot] % mod3;
        for (auto x : v) {
          ans = ans * getfac2(x) % mod3;
        }
      }
      res++;
     // cout<<"i="<<i<<" "<<res<<" "<<ans<<endl;
      tmp /= 2LL;
      for (int j = 1; j <= n; ++j) {
        a[j] *= 2;
      }
    }
    ll num=0LL;
    for (int i = 1; i <= n; ++i) {
      num += b[i]-a[i];
    }
    res += num;
    // ll res2 = fac[17] * getfac2(fac[6]) % mod3 * getfac2(fac[4]) % mod3 * getfac2(fac[4]) % mod3 * getfac2(fac[2]) % mod3;
    // ll res3 = comb(17, 6) * comb(11, 1) % mod3 * comb(10, 4) % mod3 * comb(6, 4) % mod3 * comb(2, 2) % mod3;
    // cout<<"res2="<<res2<<endl;
    // cout<<"res3="<<res3<<endl;
   // cout<<"num="<<num<<endl;
    if (num >= mod3) {
      ans *= 0LL;
    } else {
      ans = ans * fac[num] % mod3;
    }
    for (int i = 1; i <= n; ++i) {
      ll dt = b[i]-a[i];
      if (dt) {
        ans = ans * getfac2(dt) % mod3;
      }
    }
    printf("%lld %lld\n", res, ans);
  }
  return 0;
}
