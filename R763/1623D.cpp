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
int n, m, q, k;
int a[N];
ll b[N];
int t;
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int r1, c1, r2, c2;
    int p;
    scanf("%d%d%d%d%d%d%d", &n, &m, &r1, &c1, &r2, &c2, &p);
    ll pp = (100-p)%mod * getpw(100, mod-2) % mod;
   // cout<<"pp="<<pp<<endl;
    ll cur = 1LL;
    ll tot = 0LL;
    int cnt=0;
    int dr = 1, dc = 1;
    int cr = r1, cc = c1;
    int ub = 4*(n-1)*(m-1)/getgcd(n-1,m-1);
    for (int i = 1; i <= ub; ++i) {
      if (cr == r2 || cc == c2) {
        cur = cur * pp % mod;
      }
      tot = (tot + cur) % mod;
    //  cout<<cur<<" "<<tot<<endl;
      if (cr + dr < 1 || cr + dr > n) {
        dr = -dr;
      }
      if (cc + dc < 1 || cc + dc > m) {
        dc = -dc;
      }
      cr += dr;
      cc += dc;
    }
    cur = (1 - cur + mod) % mod;
    tot = tot * getpw(cur, mod-2) % mod;
    printf("%lld\n", tot);
  }
  return 0;
}
