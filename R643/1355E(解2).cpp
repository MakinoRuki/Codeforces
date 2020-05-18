// 对于每个位置都枚举h[i]和h[i+1]之间的值，而不只是看端点。

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
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, a, r, m;
ll h[N];
int main() {
  cin>>n>>a>>r>>m;
  ll sum=0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &h[i]);
    sum += h[i];
  }
  sort(h+1, h+1+n);
  ll ans = (ll)r*sum;
  ll pre = 0LL;
  for (int i = 1; i <= n; ++i) {
    ll ls = pre;
    ll rs = sum - pre - h[i];
    ll dl = (ll)(i-1)*h[i]-pre;
    ll dr = rs - (ll)(n-i)*h[i];
    ll res=0LL;
    if (a+r > m) {
      res += min(dl, dr) * (ll)m;
      if (dl > dr) {
        res += (dl-dr)*(ll)a;
      } else {
        ll det = (dr-dl)/n;
        ll res2 = (dr-dl)*(ll)r;
        if (i < n && h[i]+det < h[i+1]) {
          res2 = min(res2, det*(ll)i*(ll)m+(dr-dl-(ll)n*det)*(ll)r);
          if (dr-dl > (ll)n*det) {
            res2 = min(res2, (dr-dl-(n-i)*(det+1))*m + ((h[i]+det+1)*n-sum)*a);
          }
        }
        res += res2;
      }
    } else {
      res += dl * (ll)a + dr * (ll)r;
    }
    ans = min(ans, res);
    pre += h[i];
    //cout<<i<<" "<<ans<<endl;
  }
  // ll avg = sum/n;
  // int i;
  // for (i = 1; i <= n; ++i) {
  //   if (avg < h[i]) break;
  // }
  // if (i > n) cout<<ans<<endl;
  // else {
  //   ll sum2=0LL;
  //   for (int j = n; j >= i; --j) {
  //     sum2 += h[j];
  //   }
  //   ll det = sum2 - (n-i+1)*avg;
  //   ll pre = sum - sum2;
  //   ll need = (i-1)*avg-pre;
  //   ll res = max(need, 0LL) * m + (det-max(need,0LL))*r;
  //   ans = min(ans, res);
  //   cout<<ans<<endl;
  // }
  cout<<ans<<endl;
  return 0;
}
