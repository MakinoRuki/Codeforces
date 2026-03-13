
#include <iostream>
#include <sstream>
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
#define N 3000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
ll a[N];
ll b[N];
ll c[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h,l;
    ll x;
    scanf("%d%lld", &n, &x);
    ll tot = 0LL;
    ll mx = 0LL;
    for (int i= 1; i <= n; ++i) {
      scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
      tot += (b[i]-1)*a[i];
      if (i == 1) mx = (b[i]-1)*a[i]+a[i]-c[i];
      else mx = max(mx, (b[i]-1)*a[i]+a[i]-c[i]);
    }
    if (tot >= x) puts("0");
    else {
      ll dt = x - tot;
      if (mx <= 0) puts("-1");
      else {
        ll ans = (dt +mx - 1)/ mx;
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}

