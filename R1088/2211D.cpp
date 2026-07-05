
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
#define M 1805
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
int b[N];
int c[N];
ll fac[N];
ll fac2[N];
ll getmod(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y /= 2;
  }
  return res;
}
ll comb(ll x, ll y) {
  if (x < y) return 0LL;
  ll res= fac[x] * fac2[y] % mod * fac2[x-y] % mod;
  return res;
}
int main() {
  fac[0]=1;
  fac2[0]=1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod;
    fac2[i] = getmod(fac[i], mod-2);
  }
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
 //  ll x, y;
   scanf("%d", &n);
 //  string s;
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &b[i]);
     a[i]=0;
   }
   for (int i = 0; i <= 40; ++i) {
     c[i]=0;
   }
   for (int i = n; i >= 1; --i) {
     vector<int> bs;
     bs.clear();
     for (int j = 0; j < 29; ++j) {
       if ((1<<j)&b[i]) {
         c[j] = i;
         bs.push_back(j);
       }
     }
     for (auto bb : bs) {
       for (int j = i-1; j >= 1; --j) {
         b[j] = (b[j] - comb(i,j) * (1<<bb) % mod + mod) % mod;
       }
     }
   }
   for (int i = 0; i < 29; ++i) {
     int num = c[i];
     for (int j = 1; j <= num; ++j) {
       a[j] |= (1<<i);
     }
   }
   for (int i = 1; i <= n; ++i) {
     printf("%d ", a[i]);
   }
   cout<<endl;
 }
 return 0;
}
