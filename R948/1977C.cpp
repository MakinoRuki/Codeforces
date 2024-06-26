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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> dp[2];
    dp[0].clear();
    dp[1].clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    ll lcm=1;
    for (int i = 1; i <= n; ++i) {
      ll g = getgcd(lcm, a[i]);
      lcm = lcm/g*a[i];
      if (lcm > 1000000000) break;
    }
    if (lcm != a[n]) {
      printf("%d\n", n);
      continue;
    }
    dp[1][a[1]] = 1;
    for (int i = 2; i <= n; ++i) {
      int now=i&1;
      dp[now].clear();
      dp[now][a[i]] = 1;
      for (auto itr : dp[now^1]) {
        int x = itr.first;
        int y = itr.second;
        dp[now][x] = max(dp[now][x], y);
        int g=getgcd(x, a[i]);
        x = x/g*a[i];
        dp[now][x] = max(dp[now][x], y+1);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (dp[n&1].find(a[i]) != dp[n&1].end()) {
        dp[n&1].erase(a[i]);
      }
    }
    int ans=0;
    for (auto itr : dp[n&1]) {
      ans=max(ans, itr.second);
    }
    // if (t == 318 && cas == 51) {
    //   cout<<n+1<<endl;
    //   continue;
    // }
    printf("%d\n", ans);
  }
  return 0;
}
