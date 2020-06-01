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
#define N 502
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
ll l, r;
ll solve(ll x) {
  if (x==0) return 0LL;
  ll tot=0LL;
  ll cnt=0LL;
  ll pw = 0;
  ll es = 2;
  ll os = 1;
  while(cnt < x) {
    ll num = (1LL<<pw);
    if (x-cnt < (1LL<<pw)) {
      num = x-cnt;
    }
    ll y = num%mod;
    if (pw%2==0) {
      ll det = (os+y-1+mod)%mod*y%mod;
      tot = (tot+det)%mod;
      os = (os + 2LL*num)%mod;
    } else {
      ll det = (es+y-1+mod)%mod*y%mod;
      tot= (tot+det)%mod;
      es = (es+2LL*num)%mod;
    }
    cnt += num;
    pw++;
  }
  return tot;
}
int main() {
  scanf("%lld%lld", &l, &r);
//  cout<<solve(r)<<" "<<solve(l-1)<<endl;
  ll ans = (solve(r) - solve(l-1) + mod) % mod;
  cout<<ans<<endl;
  return 0;
}
