#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 500005
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n;
    scanf("%lld", &n);
    ll l = 0, r = 2000000000LL;
    while(l < r) {
      ll mid = (l+r)/2;
    //  cout<<l<<" "<<r<<" "<<mid<<endl;
      ll tot = 0LL;
      if (mid <= 1) {
        tot = 0LL;
      } else if (mid == 2) {
        tot = 2LL;
      } else if (mid == 3) {
        tot = 6LL;
      } else if (mid == 4) {
        tot = 10LL;
      } else if (mid == 5) {
        tot = 16LL;
      } else if (mid == 6) {
        tot= 24LL;
      } else {
        ll dt = mid - 3;
        ll q = dt/ 3 ;
        ll x = dt % 3;
        if (6LL * q >= (n+q-1)/q) {
          tot= n;
        } else {
          tot += 6LL * q * q;
          if (tot >= n - 12LL * q) {
            tot = n;
          } else {
            tot += 12LL*q;
            ll y = 0LL;
            if (x >= 1) y += 2LL * (q+1);
            if (x >= 2) y += 2LL * (q+1)+1;
            y += 3LL;
            if (tot >= n-y*2) {
              tot = n;
            } else {
              tot += y*2LL;
            }
          }
        }
      }
      if (tot >= n) {
        r= mid;
      } else {
        l =mid+1;
      }
    }
    printf("%lld\n", r);
  }
  return 0;
}
