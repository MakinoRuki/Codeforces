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
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, a;
int b[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
int main() {
  cin>>n>>m>>a;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
  }
  ll ans = getpw(a, n-2*b[m]);
  for (int i = 1; i <= m; ++i) {
    ll cur = getpw(a, (i==1 ? b[i] : b[i]-b[i-1]));
    ll cur2 = (cur*cur%mod2 + cur) % mod2;
    cur2 = cur2 * getpw(2LL, mod2-2) % mod2;
    ans = ans * cur2 % mod2;
  }
  cout<<ans<<endl;
  return 0;
}
