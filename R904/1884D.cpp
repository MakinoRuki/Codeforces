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
#define N 1000005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
ll dp[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", & n);
    for (int i =1; i <= n; ++i) {
      cnt[i] = 0;
      dp[i] = 0LL;
      vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
      vis[a[i]] = true;
    }
    ll tot = (ll)n*(ll)(n-1)/2LL;
    for (int i = n; i >= 1; --i) {
      ll num= cnt[i];
      for (int j = 2*i; j <= n; j += i) {
        if (vis[i]) vis[j] = true;
        num += cnt[j];
        dp[i] -= dp[j];
      }
      if (num) dp[i] += num*(num-1)/2;
    }
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) tot -= dp[i];
    }
    printf("%lld\n", tot);
  }
  return 0;
}
