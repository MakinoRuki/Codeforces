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
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int c0=0, c1=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == 0) {
        c0++;
      } else if (a[i] == 1) {
        c1++;
      }
    }
    ll ans = (1LL<<c0) * (ll)c1;
    printf("%lld\n", ans);
  }
  return 0;
}
