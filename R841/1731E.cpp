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
int a[N];
ll dp[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    //ll n;
    ll m;
    scanf("%d%lld", &n, &m);
  //  cout<<getres(n)<<" "<<getres(n-1)<<endl;
    for (int i = n; i >= 1; --i) {
      ll x = n/i;
      dp[i] = x * (x-1)/2;
      for (int j = i * 2; j <= n; j += i) {
        dp[i] -= dp[j];
      }
    }
    ll tot = 0LL;
    for (int i = n; i >= 2; --i) {
      ll dt = min(dp[i], (ll)m);
      ll dt2 = dt/(i-1);
      tot += dt2 * i;
      m -= dt2 * (i-1);
    }
    if (m <= 0) printf("%lld\n", tot);
    else puts("-1");
  }
  return 0;
}
