#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#define eps 1e-7
#define M 502
#define N 50002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
ll getpw(ll x, ll y) {
  ll res= 1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    // int pw=0;
    // ll sum=0LL;
    // k++;
    // while(sum+(1<<pw) < k) {
    //   sum += (1<<pw);
    //   pw++;
    // }
    // cout<<pw<<endl;
    // ll ans = 0LL;
    // while(pw >= 0) {
    //   if ((1<<pw)+1 <= k) {
    //     ans = (ans + getpw(n, pw)) % mod;
    //     k -= (1<<pw);
    //   }
    //   pw--;
    // }
    ll ans = 0LL;
    for (int i = 30; i>=0; --i) {
      if ((1LL<<i) <= k) {
        ans = (ans + getpw(n, i)) % mod;
        k -= (1LL<<i);
      }
    }
    //k--;
    // for (int i = pw; i > 0; --i) {
    //   if ((1<<pw) <= k) {
    //     ans = (ans + getpw(n, pw)) % mod;
    //     k -= (1<<pw)-1;
    //   }
    // }
    printf("%lld\n", ans);
  }
  return 0;
}
