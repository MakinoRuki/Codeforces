#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <set>
#include <list>
#include <random>
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int c;
int x[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i =1; i <= n; ++i) {
      scanf("%d", &x[i]);
    }
    ll tot=0LL;
    for (int i = n; i >= 0; --i) {
      sum[i] = tot;
      tot += (ll)x[i];
    }
    ll ans=0LL;
    x[0] = 0;
    int pre = 0;
    for (int i = 1; i <= n; ++i) {
      ans += (ll)b * (ll)(x[i] - x[pre]);
      ll xx = (ll) a * (ll)(x[i] - x[pre]) + (ll)b * (sum[i] - (ll)(n-i) * (ll)x[i]);
      ll yy = (ll)b * (ll)(sum[i] - (ll)(n-i) * (ll)x[pre]);
      if (xx < yy) {
        ans += (ll)a * (ll)(x[i] - x[pre]);
        pre = i;
      }
    //  cout<<i<<" "<<ans<<" "<<pre<<endl;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
