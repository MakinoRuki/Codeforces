#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int v[N];
ll sum[N];
int main() {
  cin>>n;
  sum[0] = 0LL;
  ll tot=0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &v[i]);
    tot += v[i];
    sum[i] = v[i] + sum[i-1];
  }
  for (int i = 1; i <= n; ++i) {
    sum[i] = (sum[i] + i-1)/i;
    sum[i] = max(sum[i], sum[i-1]);
  }
  cin>>q;
  while(q-->0) {
    ll tm;
    scanf("%lld", &tm);
    if (tm < sum[n]) {
      puts("-1");
    } else {
      ll ans = (tot + tm-1) /tm;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
