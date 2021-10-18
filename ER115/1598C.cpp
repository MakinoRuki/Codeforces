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
int t, n;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += (ll)a[i];
    }
    if ((2*tot) % n != 0) {
      puts("0");
      continue;
    }
    map<int, int> mp;
    mp.clear();
    ll ans = 0LL;
    ll x = (2*tot)/n;
    for (int i = n; i >= 1; --i) {
      ans += mp[x-a[i]];
      mp[a[i]]++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
