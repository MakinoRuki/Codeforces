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
#define M 202
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
ll a[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    ll x = 0;
    ll y = 0;
    for (ll i = 0; i <= r-l; ++i) {
      x ^= i;
    }
    for (int i = 1; i <= r-l+1; ++i) {
      scanf("%lld", &a[i]);
      y ^= a[i];
    }
    ll n = (r-l+1);
    if (n % 2) {
      printf("%lld\n", x^y);
    } else {
      // for (int i = 0; i <= r-l; ++i) {
      //   ll x2 = x;
      //   ll y2 = y ^ a[i + 1];
      //   if ((x2 ^ y2) == a[i + 1]) {
      //     printf("%lld\n", x2 ^ y2);
      //     break;
      //   }
      // }
      // sort(a+1, a+n+1);
      // int i;
      // for (i = 1; i < n; ++i) {
      //   if (a[i] + 1 != a[i+1]) {
      //     break;
      //   }
      // }
      // printf("%lld\n", a[i]);
      ll res = 0LL;
      for (int i = 17; i >= 0; --i) {
        int n0 = 0, n1 = 0;
        int m1 = 0, m0 = 0;
        for (int j = 0; j <= r; ++j) {
          if ((1<<i) & j) n1++;
          else n0++;
        }
        for (int j = 1; j <= n; ++j) {
      //    if (i == 3) cout<<"x="<<a[j]<<endl;
          if ((1<<i) & a[j]) m1++;
          else m0++;
        }
    //    if (i == 3) cout<<n0<<" "<<n1<<" "<<m0<<" "<<m1<<endl;
        if (n0 == m1 && n1 == m0) {
          res |= (1LL<<i);
        }
      }
      printf("%lld\n", res);
    }
  }
  // cin>>n;
  // for (int i = 0; i <= n; ++i) {
  //   cout<<"i="<<i<<endl;
  //   for (int j = 0; j <= n; ++j) {
  //     cout<<(i^j)<<" ";
  //   }
  //   cout<<endl;
  // }
  return 0;
}
