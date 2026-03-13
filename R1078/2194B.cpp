
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
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
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
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x,y;
    ll tot=0LL;
    ll ans=0LL;
    scanf("%d%lld%lld", &n, &x, &y);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += (a[i]/x)*y;
      ans=max(ans, (ll)a[i]);
    }
    for (int i =1; i <= n; ++i) {
      ans = max(ans, tot-(a[i]/x)*y+a[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

