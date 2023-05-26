#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 300005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
//int a[N];
ll a1,x,y;
ll res[2][10];
int main() {
  cin>>n>>a1>>x>>y>>m>>k;
  ll ans = 0LL;
  memset(res, 0LL, sizeof(res));
  ll sum = 0LL;
  for (int i = 1; i <= n; ++i) {
    if (i > 1) {
      a1 = ((a1 * x) + y) % m;
    }
    sum = (sum + a1) % mod2;
    int now = i&1;
    //res[now][0] = sum;
    for (int j = 1; j <= k; ++j) {
      if (j==1) res[now][j] = (res[now^1][j] + sum) % mod2;
      else res[now][j] = (res[now^1][j] + res[now^1][j-1]) % mod2;
    }
    ll tmp = res[now][k] * (ll)i;
    ans ^= tmp;
  }
  printf("%lld\n", ans);
  return 0;
}
