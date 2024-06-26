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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n+1; ++i) {
      scanf("%d", &b[i]);
    }
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      tot += (ll)abs(a[i]-b[i]);
    }
    ll ans = (1LL<<61)-1;
    for (int i = 1; i <= n; ++i) {
      ll tmp=tot;
      tmp -= abs(a[i]-b[i]);
      if (a[i] >= b[i] && a[i] >= b[n+1]) {
        tmp += a[i]-min(b[i], b[n+1])+1;
      } else if (a[i] >= b[i] && a[i] <= b[n+1]) {
        tmp += b[n+1]-b[i]+1;
      } else if (a[i] <= b[i] && a[i] >= b[n+1]) {
        tmp += b[i]-b[n+1]+1;
      } else {
        tmp += max(b[n+1], b[i])-a[i]+1;
      }
      ans = min(ans, tmp);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
