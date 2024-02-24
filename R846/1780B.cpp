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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
ll sum[N];
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    sum[0] = 0LL;
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += a[i];
      sum[i] = sum[i-1] + a[i];
    }
    ll ans=0LL;
    for (int i = 1; i < n; ++i) {
      ll g = getgcd(sum[i], tot);
      ans = max(ans, g);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
