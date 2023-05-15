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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int l[N], r[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &l[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &r[i]);
    }
    ll ans = -1;
    ll len = 0;
    int cnt1=0;
    int cnt2=0;
    for (int i = 1; i <= n; ++i) {
      if (len < k) {
        ll dt = k-len;
        ll cl = r[i]-l[i]+1;
        if (dt <= cl) {
          ll res = l[i]+dt-1+2LL*(cnt2+1);
          ans = (ans < 0 ? res : min(ans, res));
        } else {
          ll dt2 = dt - cl;
          if (cnt1 >= dt2) {
            ll res = r[i]+2LL*(dt2+cnt2+1);
            ans = (ans < 0 ? res : min(ans, res));
          }
        }
      }
      if (r[i]-l[i]+1 > 1) {
        len += (ll)(r[i]-l[i]+1);
        cnt2++;
      } else {
        cnt1++;
      }
     // cout<<"i="<<i<<" "<<ans<<endl;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
