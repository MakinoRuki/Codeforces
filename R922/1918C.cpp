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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll a,b,r;
    scanf("%lld%lld%lld",&a,&b,&r);
    ll ans=(1LL<<62)-1;
    for (int i = 61; i >= 0; --i) {
      ll pre=0LL;
      ll a1=0LL;
      ll b1=0LL;
      ll cur=0LL;
      bool ok=true;
      for (int j = 61; j > i; --j) {
        if (((1LL<<j)&a) != ((1LL<<j)&b)) {
          ok=false;
          break;
        }
        if ((1LL<<j)&a) {
          a1 |= (1LL<<j);
          b1 |= (1LL<<j);
          pre |= (1LL<<j);
        }
      }
      if (!ok) continue;
      if (pre > r) continue;
      for (int j = i; j >= 0; --j) {
        ll res=0LL;
        if ((1LL<<j) &a) a1 |= (1LL<<j);
        if ((1LL<<j)&b) b1 |= (1LL<<j);
        res = (a1 ^ pre) - (b1 ^ pre);
       // if (i == 3) cout<<"j="<<j<<" "<<a1<<" "<<b1<<" "<<pre<<" "<<res<<endl;
        if (pre + (1LL<<j) <= r) {
          ll r1 = pre + (1LL<<j);
         // if (i==3) cout<<r1<<" "<<(a1^r1)<<" "<<(b1^r1)<<endl;
          if (abs((a1 ^ r1)-(b1 ^ r1)) < abs(res)) {
            res = (a1 ^ r1) - (b1 ^ r1);
            pre |= (1LL<<j);
          }
        }
       // if (i == 3) cout<<"j2="<<j<<" "<<res<<endl;
        cur = res;
      }
      ans = min(ans, abs(cur));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
