/* 经典组合数公式
C(1+x,x)+C(2+x,x)+...+C(n+x,x)=C(n+x+1,x+1)-1 */

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
#include <stack>
#include <bitset>
#include <chrono>
#define N 1000005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int c[N];
ll calc(int tot, ll md) {
  ll res=1LL;
  for (int i =1; i <= tot; ++i) {
    res = res*(ll)i % md;
  }
  return res;
}
ll getpw(ll x, ll y, ll md) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%md;
    x=x*x%md;
    y/=2;
  }
  return res;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  ll md = 1000003;
  cin>>n>>m;
  ll pnm=calc(n+m, md);
  ll pm=getpw(calc(m, md), md-2, md);
  ll pn=getpw(calc(n, md), md-2, md);
  ll ans = pnm*pm%md*pn%md;
  ans = (ans - 1 + md) % md;
  cout<<ans<<endl;
  return 0;
}
 
