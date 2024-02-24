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
#define N 300005
#define M 2002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d%d", &n, &k, &x);
    sum[0]=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1] + a[i];
    }
    ll ans=0LL;
    if (x <= n) {
      ans = -sum[n]+2LL*sum[n-x];
    } else {
      ans = -sum[n];
    }
    for (int i = 1; i <= min(n, k); ++i) {
      int cur = n-i;
      if (x <= cur) {
        ans = max(ans, -sum[cur]+2LL*sum[cur-x]);
      } else {
        ans =max(ans, -(ll)sum[cur]);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
