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
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int b[N];
int lm[N], rm[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    //ll n;
    scanf("%d", &n);
    lm[0] = -1000000000;
    rm[n+1] = -1000000000;
    for (int i =1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
      lm[i] = max(lm[i-1], b[i]+i);
    }
    for (int i = n; i >= 1; --i) {
      rm[i] = max(rm[i+1], b[i]-i);
    }
    ll ans = -1000000000;
    for (int i = 2; i < n; ++i) {
      ans = max(ans, (ll)b[i] + (ll)lm[i-1] + (ll)rm[i+1]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
