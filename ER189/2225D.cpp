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
#define N 500005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
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
int p;
ll calc0(ll x) {
    ll n0 = 1;
    if (x >= 3) {
        n0 += (x - 3) / 4 + 1;
    }
    return n0;
}
ll calc1(ll x) {
  ll n1 = 0;
  if (x >= 1) {
      n1 = (x - 1) / 4 + 1;
  }
  return n1;
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
  // int ss=0;
  // for (int i = 1; i <= 100; ++i) {
  //   ss ^= i;
  //   cout<<ss<<" ";
  // }
  // cout<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x,n;
    scanf("%lld%lld", &n, &x);
   // cout<<calc0(x-1)<<" "<<calc0(n)<<" "<<calc1(x-1)<<" "<<calc1(n)<<endl;
    ll ln0 = calc0(x-1)%mod2;
    ll ln1 = calc1(x-1)%mod2;
    ll rn0 = (calc0(n)%mod2-calc0(x-1)%mod2+mod2)%mod2;
    ll rn1 = (calc1(n)%mod2-calc1(x-1)%mod2+mod2)%mod2;
    ll ans = (ln0*rn0%mod2+ln1*rn1%mod2)%mod2;
    printf("%lld\n", ans);
  }
  return 0;
}

