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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll b,c,d;
    scanf("%lld%lld%lld", &b, &c, &d);
    bool ok=true;
    ll a = 0LL;
    for (int i = 0; i <= 63; ++i) {
      if ((b&(1LL<<i)) && (c&(1LL<<i)) && !(d&(1LL<<i))) {
        a |= (1LL<<i);
      } else if (!(b&(1LL<<i)) && !(c&(1LL<<i)) && (d&(1LL<<i))) {
        a |= (1LL<<i);
      } else if (!(b&(1LL<<i)) && (c&(1LL<<i)) && (d&(1LL<<i))) {
        ok=false;
        break;
      } else if ((b&(1LL<<i)) && !(c&(1LL<<i)) && !(d&(1LL<<i))) {
        ok = false;
        break;
      }
    }
    if (!ok) puts("-1");
    else printf("%lld\n", a);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

