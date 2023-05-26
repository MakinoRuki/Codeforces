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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
ll sum[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    //ll n;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    sum[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1] + a[i];
    }
    ll ans = 0LL;
    for (int i = 0; i <= k; ++i) {
      ll dt = sum[n-i] - sum[2*(k-i)];
      ans = max(ans, dt);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
