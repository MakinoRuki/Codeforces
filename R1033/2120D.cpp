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
#define M 505
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
ll getpw(ll x, ll y) {
    ll res=1LL;
    while(y) {
        if (y&1) res= res*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return res;
}
ll comb(ll x, ll y) {
    ll res = 1LL;
    for (int i =1 ; i <= y; ++i) {
        res = res * ((x-i+1)%mod) % mod;
    }
    ll fac = 1LL;
    for (int i =1; i <= y; ++i) {
        fac= fac*i % mod;
    }
    res = res * getpw(fac, mod-2) % mod;
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll a,b,k;
    scanf("%lld%lld%lld", &a, &b, &k);
    ll n = k * (a-1) + 1;
    ll m = (k % mod * comb(n, a) % mod * ((b-1)%mod) % mod + 1) % mod;
    n %= mod;
    printf("%lld %lld\n", n, m);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
