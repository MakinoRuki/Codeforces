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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
ll v[N];
int main() {
  cin>>n>>q;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  while(q-->0) {
    ll k;
    scanf("%lld", &k);
    for (int i = 1; i <= n; ++i) {
      v[i]=a[i];
    }
    ll ans=0LL;
    for (int b = 62; b >= 0; b--) {
      ll tot=0LL;
      for (int i = 1; i <= n; ++i) {
        ll dt = (1LL<<b)-(v[i]&((1LL<<(b+1))-1));
        if (dt > 0) {
          if (tot <= k-dt){
            tot += dt;
          }else {
            tot = k+1;
            break;
          }
        }
      }
      if (tot <= k) {
        ans |= (1LL<<b);
        k -= tot;
        for (int i = 1; i <= n; ++i) {
          ll dt = (1LL<<b)-(v[i]&((1LL<<(b+1))-1));
          if (dt > 0) {
            v[i] += dt;
          }
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
