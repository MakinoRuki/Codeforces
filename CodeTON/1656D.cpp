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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
ll n;
int t;
int c;
int a[N];
// int mx;
// bool check(ll x) {
//   for (ll k = 2; k <= x; ++k) {
//     ll det = x - k*(k-1)/2;
//     if (det >= 0 && ((det % k) == 0)) {
//       cout<<"k="<<k<<endl;
//      // mx = max(mx, k);
//      // return true;
//     }
//   }
//   return false;
// }
bool check(ll x) {
  if (x-1 > (2LL*n) / x) {
    return false;
  }
  ll det = n - x*(x-1)/2;
  if (det >= x && ((det % x) == 0)) {
    return true;
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    //ll n;
    scanf("%lld", &n);
    if (n == 6) {
      puts("3");
      continue;
    }
    if (n % 2) {
      puts("2");
    } else {
      ll x = n;
      while(x % 2 == 0) {
        x/=2;
      }
      if (x == 1) {
        puts("-1");
      } else {
        if ((n-6)% 4 == 0) {
          puts("4");
        } else {
          ll c = 2LL;
          bool found=false;
          while(c <= n) {
            if (check(c)) {
              printf("%lld\n", c);
              found=true;
              break;
            } else {
              c *= 2LL;
            }
          }
          if (found) continue;
          if (check(x)) {
            printf("%lld\n", x);
          } else if (check(7)) {
            printf("%lld\n", 7LL);
          } else if (check(8)) {
            printf("%lld\n", 8LL);
          } else if (check(3)) {
            printf("%lld\n", 3LL);
          } else if (check(5)) {
            printf("%lld\n", 5LL);
          } else {
            puts("-1");
          }
          //printf("%lld\n", x);
        }
      }
    }
  }
  // mx = 0;
  // ll x=100096;
  // while(x % 2 == 0) {
  //   x/=2;
  // }
  // cout<<x<<endl;
  // for (int i = 100000; i <= 100500; i += 4) {
  //   cout<<"i="<<i<<endl;
  //  // cout<<check(i)<<endl;
  //   check(i);
  // }
  // cout<<mx<<endl;
  return 0;
}
