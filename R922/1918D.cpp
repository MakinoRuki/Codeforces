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
#include <list>
#define N 300005
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
ll sum[N];
ll dp[N];
bool check(ll x) {
  dp[0] = 0LL;
  list<int> v;
  v.clear();
  v.push_back(0);
  for (int i = 1; i <= n; ++i) {
    while(!v.empty() && sum[i]-sum[v.front()]-a[i] > x) {
      v.pop_front();
    }
    if (!v.empty()) {
      dp[i] = dp[v.front()]+a[i];
    } else {
      dp[i] = a[i];
    }
    while(!v.empty() && dp[i] <= dp[v.back()]) {
      v.pop_back();
    }
    v.push_back(i);
  }
  for (int i = 0; i <= n; ++i) {
    if (dp[i] <= x && sum[n]-sum[i] <= x) {
      return true;
    }
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    sum[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += (ll)a[i];
      sum[i] = sum[i-1]+(ll)a[i];
    }
    ll l = 0, r = tot;
    while(l < r) {
      ll mid = (l+r)/2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%lld\n", r);
  }
  return 0;
}
